#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5E4 + 10, M = N << 2;
int w[N], res[M];
struct Node{
	int l, r, id;
	bool operator<(const Node& t) const { return r < t.r; }
};
vector<Node> area;
int t[N];
int lowbit(int x) { return x & -x;}
void add(int x,int c) { for (int i=x;i<N;i+=lowbit(i))t[i]+=c;}
int ask(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += t[i];
	return res;
}
int ask(int l, int r) { return ask(r) - ask(l - 1); }
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)cin>>w[i]; 
	int m; cin >> m;
	for (int i = 1; i <= n; ++i){
		int l, r;cin>>l>>r;
		area.push_back({ l, r, i });
	}
	sort(area.begin(), area.end());
	unordered_map<int, int> mp;
	int pos = 0;
	for (auto& op : area) {
		int l = op.l, r = op.r, id = op.id;
		while (pos + 1 <= r) {
			pos++;
			add(pos, 1);
			if (mp[w[pos]]) add(mp[w[pos]], -1);
			mp[w[pos]] = pos;
		}
		res[id] = ask(l, r);
	}
	for (int i = 1; i <= n; ++i)cout<<res[i]<<endl;
	return 0;
}
