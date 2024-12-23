#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
class IO {
private:
    // 处理整数类型的快速输入
    void _read(int &x) {
        x = 0;
        char ch = getchar();
        bool f = 0;
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = 1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = getchar();
        }
        if (f) x = -x;
    }

    // 处理浮点数类型的快速输入
    void _read(double &x) {
        x = 0;
        char ch = getchar();
        bool f = 0;
        while ((ch < '0' || ch > '9') && ch != '.' && ch != '-') {
            if (ch == '-') f = 1;
            ch = getchar();
        }
        bool is_decimal = false;
        double frac = 0.1;
        while ((ch >= '0' && ch <= '9') || ch == '.') {
            if (ch == '.') {
                is_decimal = true;
            } else {
                if (is_decimal) {
                    x += (ch - '0') * frac;
                    frac *= 0.1;
                } else {
                    x = x * 10 + (ch - '0');
                }
            }
            ch = getchar();
        }
        if (f) x = -x;
    }

    // 处理字符串类型的快速输入
    void _read(string &x) {
        x.clear();
        char ch = getchar();
        while (isspace(ch)) ch = getchar();
        while (!isspace(ch) && ch != EOF) {
            x.push_back(ch);
            ch = getchar();
        }
    }

    // 处理整数类型的快速输出
    void _write(int x) {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        if (x >= 10) _write(x / 10);
        putchar(x % 10 + '0');
    }

    // 处理浮点数类型的快速输出，支持动态精度
    void _write(double x, int precision) {
        cout << fixed << setprecision(precision) << x;
    }

    // 处理字符串类型的快速输出
    void _write(const string &x) {
        for (char c : x) putchar(c);
    }

    // 处理容器的快速输入
    template <typename T>
    void _read(vector<T> &v, int n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) _read(v[i]);
    }

    // 处理容器的快速输出
    template <typename T>
    void _write(const vector<T> &v) {
        for (const auto &elem : v) {
            _write(elem);
            putchar(' ');
        }
    }

public:
    // 构造函数：自动初始化同步和绑定
    IO() {
        ios::sync_with_stdio(1);
        cin.tie(&cout); // 确保绑定
    }

    // 统一的读取接口
    template <typename T>
    void read(T &x) {
        _read(x);
    }

    template <typename T>
    void read(vector<T> &v, int n) {
        _read(v, n);
    }

    // 统一的写出接口
    template <typename T>
    void write(const T &x) {
        _write(x);
    }

    void write(double x, int precision = 6) {
        _write(x, precision);
    }

    template <typename T>
    void write(const vector<T> &v) {
        _write(v);
    }

    // 输出换行
    void newline() {
        putchar('\n');
    }
}io;
const int maxn = 1000019,INF = 1e9;
int na;
int ch[maxn][2];
int val[maxn],dat[maxn];
int sz[maxn],cnt[maxn];
int tot,root;
int New(int v){
	val[++tot] = v;
	dat[tot] = rand();
	sz[tot] = 1;
	cnt[tot] = 1;
	return tot;
	}
void pushup(int id){
	sz[id] = sz[ch[id][0]] + sz[ch[id][1]] + cnt[id];
	}
void build(){
	root = New(-INF),ch[root][1] = New(INF);
	pushup(root);
	}
void Rotate(int &id,int d){
	int temp = ch[id][d ^ 1];
	ch[id][d ^ 1] = ch[temp][d];
	ch[temp][d] = id;
	id = temp;
	pushup(ch[id][d]),pushup(id);
	}
void insert(int &id,int v){
	if(!id){
		id = New(v);
		return ;
		}
	if(v == val[id])cnt[id]++;
	else{
		int d = v < val[id] ? 0 : 1;
		insert(ch[id][d],v);
		if(dat[id] < dat[ch[id][d]])Rotate(id,d ^ 1);
		}
	pushup(id);
	}
void Remove(int &id,int v){
	if(!id)return;
	if(v == val[id]){
		if(cnt[id] > 1){cnt[id]--,pushup(id);return ;}
		if(ch[id][0] || ch[id][1]){
			if(!ch[id][1] || dat[ch[id][0]] > dat[ch[id][1]]){
				Rotate(id,1),Remove(ch[id][1],v);
				}
			else Rotate(id,0),Remove(ch[id][0],v);
			pushup(id);
			}
		else id = 0;
		return;
		}
	v < val[id] ? Remove(ch[id][0],v) : Remove(ch[id][1],v);
	pushup(id);
	}
int get_rank(int id,int v){
	if(!id)return 1;
	if(v == val[id])return sz[ch[id][0]] + 1;
	else if(v < val[id])return get_rank(ch[id][0],v);
	else return sz[ch[id][0]] + cnt[id] + get_rank(ch[id][1],v);
	}
int get_val(int id,int rank){
	if(!id)return INF;
	if(rank <= sz[ch[id][0]])return get_val(ch[id][0],rank);
		else if(rank <= sz[ch[id][0]] + cnt[id])return val[id];
	else return get_val(ch[id][1],rank - sz[ch[id][0]] - cnt[id]);
	}
int get_pre(int v){
	int id = root,pre;
	while(id){
		if(val[id] < v)pre = val[id],id = ch[id][1];
		else id = ch[id][0];
		}
	return pre;
	}
int get_next(int v){
	int id = root,next;
	while(id){
		if(val[id] > v)next = val[id],id = ch[id][0];
		else id = ch[id][1];
		}
	return next;
	}
int main(){
	build();
	io.read(na);
	for(int i = 1;i <= na;i++){
		int cmd,x;io.read(cmd);io.read(x);
		if(cmd == 1)insert(root,x);
		else if(cmd == 2)Remove(root,x);
		else if(cmd == 3)io.write(get_rank(root,x) - 1),io.newline();
		else if(cmd == 4)io.write(get_val(root,x + 1)),io.newline();
		else if(cmd == 5)io.write(get_pre(x)),io.newline();
		else if(cmd == 6)io.write(get_next(x)),io.newline();
		}
	return 0;
}