/*
 * 数据生成器 + 解题代码
 * 说明：
 *  1) 本程序一次性生成 10 对输入输出文件。
 *  2) 每次生成一个数据文件 battle_plus_{id}.in，并立即调用解题逻辑生成对应输出文件 battle_plus_{id}.out。
 *  3) 使用中文注释，使用 bits/stdc++.h, std 命名空间，以符合题目要求。
 *  4) 保证生成的 N, M 在 [950, 1000] 范围内，M <= N，序列 A 的取值范围在 [1, 6000]。
 *  5) 程序中所有文件读写均使用 Linux 换行符输出（在 Windows 环境下编译时可设置）。
 *
 */
#include <bits/stdc++.h>
using namespace std;

// ----------------------
// 全局常量、变量定义区
// ----------------------
static const int P = 1000000007;  // 取模
static const int MAXN = 2000;     // 为安全起见，稍微开大一些
int n, m;                        // n, m 表示序列长度与子序列长度
int a[MAXN], b[MAXN], cFenwicks[MAXN];  // a 存放原序列, b 用于去重排序, Fenwicks树/树状数组
int f[2000][2000];               // f[i][j] 表示以 j 结尾的长度为 i 的严格递增子序列个数
int Tcase;                       // 用于输出 Case # 编号

// ----------------------
// Fenwicks 树相关操作
// ----------------------
void fenwicks_add(int x, int y) {
    while (x <= n + 1) {
        cFenwicks[x] = (cFenwicks[x] + y) % P;
        x += x & -x;
    }
}

int fenwicks_ask(int x) {
    int ans = 0;
    while (x > 0) {
        ans = (ans + cFenwicks[x]) % P;
        x -= x & -x;
    }
    return ans;
}

// ----------------------
// 解题核心函数
// ----------------------
void The_Battle_of_Chibi() {
    // 读入 n, m
    cin >> n >> m;
    // 读入序列 a
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 将 a 拷贝到 b, 并对 b 去重排序
    memcpy(b, a, sizeof(b));
    sort(b + 1, b + n + 1);
    // 通过二分将 a[i] 映射到离散化后的值
    for (int i = 1; i <= n; i++) {
        a[i] = int(lower_bound(b + 1, b + n + 1, a[i]) - (b + 1)) + 1;
    }

    // 初始化
    // f[i][j]: 以第 j 个元素结尾的长为 i 的严格递增子序列个数
    // 这里需要将 f 全局清零
    memset(f, 0, sizeof(f));
    // a[0] = 1 是题目中为了 Fenwicks 树更新时特意多定义的，但此处也可不需要
    // f[0][0] = 1 代表空序列数量
    f[0][0] = 1;  

    // 枚举子序列长度 i
    for (int i = 1; i <= m; i++) {
        // 每次进行树状数组清零
        memset(cFenwicks, 0, sizeof(cFenwicks));
        // 将空序列 f[i-1][0] 加到 Fenwicks 中 (对应 a 值 = 1)
        fenwicks_add(1, f[i - 1][0]);

        // 枚举序列位置 j
        for (int j = 1; j <= n; j++) {
            // 求以 a[j] - 1 为界的数量
            f[i][j] = fenwicks_ask(a[j] - 1);
            // 把 f[i-1][j] 再加到树状数组中，给后面的元素使用
            fenwicks_add(a[j], f[i - 1][j]);
        }
    }

    // 最终统计所有以 i (1 <= i <= n) 结尾的 m 长度严格递增子序列之和
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + f[m][i]) % P;
    }

    // 输出结果
    printf("Case #%d: %d\n", ++Tcase, ans);
}

// ----------------------
// 生成并求解的流程函数
// ----------------------
void solveOneTest(const string &inFile, const string &outFile, int N, int M, const vector<int> &arr) {
    // 1) 写入输入文件
    {
        // 以文本方式写，保证换行符为 '\n' (Linux)
        ofstream fout(inFile, ios::out | ios::binary);
        // T=1, 表示只有一组测试
        fout << 1 << "\n";
        fout << N << " " << M << "\n";
        for (int i = 0; i < N; i++) {
            fout << arr[i] << (i + 1 < N ? ' ' : '\n');
        }
        fout.close();
    }

    // 2) 重定向到输入文件，运行解题，结果输出到 outFile
    {
        freopen(inFile.c_str(), "r", stdin);
        freopen(outFile.c_str(), "w", stdout);

        // 需要将全局的 Tcase 清零，否则多次调用 Case # 会累加
        Tcase = 0;
        // 读入 T
        int t;
        cin >> t;
        while (t--) {
            The_Battle_of_Chibi();
        }

        fclose(stdin);
        fclose(stdout);
    }
}

// ----------------------
// 主函数
// ----------------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand((unsigned)time(nullptr));

    // 生成 10 组数据并求解
    for (int id = 1; id <= 10; id++) {
        // 1) 随机生成 N, M (保证 950 <= M <= N <= 1000)
        int N = rand() % 51 + 950;  // [950, 1000]
        int M = rand() % (N - 949) + 950; // 保证 M <= N, 并且 M >= 950(若要更灵活可再调整)

        // 2) 生成随机序列 A, 范围在 [1, 6000]
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 6000 + 1;
        }

        // 3) 构造输入/输出文件名
        // 注意：如果要保证 Linux 换行符，在 Windows 下需注意写文件方式
        ostringstream ossIn, ossOut;
        ossIn << "battle_plus_" << id << ".in";
        ossOut << "battle_plus_" << id << ".out";

        // 4) 将该组数据写入输入文件并进行求解，写出到输出文件
        solveOneTest(ossIn.str(), ossOut.str(), N, M, arr);
    }

    return 0;
}