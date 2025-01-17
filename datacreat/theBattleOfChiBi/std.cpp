#include<bits/stdc++.h>
using namespace std;
#define intt long long
#define untt unsigned intt
#define mk make_pair
inline intt read(){intt x=0,f=1;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;for(;ch<='9'&&ch>='0';ch=getchar())x=x*10+ch-'0';return x*f;}
inline void prin(intt x){if(x<0)putchar('-'),x=-x;if(x>9)prin(x/10);putchar(x%10+'0');return;}
inline void print(intt x,intt fl){prin(x);if(fl)puts("");else printf(" ");return;}
inline void frein(){freopen("battle_plus_1.in","r",stdin);return;}
inline void freout(){freopen("1.out","w",stdout);return;}
const intt N=1010,INF=1e17+10;
struct segtree{
	struct node{intt l,r,sum,minn,maxn;}tr[N*4];intt a[N];
	inline intt min(intt a,intt b){if(a==-1)return b;if(b==-1)return a;if(a<b)return a;return b;}
	inline void pushup(intt p){tr[p].sum=tr[p*2].sum+tr[p*2+1].sum;tr[p].minn=min(tr[p*2].minn,tr[p*2+1].minn);tr[p].maxn=min(tr[p*2].maxn,tr[p*2+1].maxn);return;}
	inline void build(intt p,intt l,intt r){tr[p].l=l;tr[p].r=r;if(l==r){tr[p].maxn=tr[p].minn=tr[p].sum=a[l];return;}intt mid=(l+r)/2;build(p*2,l,mid);build(p*2+1,mid+1,r);pushup(p);return;}
	inline void change(intt p,intt x,intt k){intt l=tr[p].l,r=tr[p].r;if(l==r){tr[p].maxn=tr[p].minn=tr[p].sum=k;return;}intt mid=(l+r)/2;if(x<=mid)change(p*2,x,k);else change(p*2+1,x,k);pushup(p);return;}
	inline intt findsum(intt p,intt fl,intt fr){intt l=tr[p].l,r=tr[p].r;if(l>=fl&&r<=fr)return tr[p].sum;intt mid=(l+r)/2,ans=0;if(mid>=fl)ans+=findsum(p*2,fl,fr);if(mid<fr)ans+=findsum(p*2+1,fl,fr);return ans;}
	inline intt findminn(intt p,intt fl,intt fr){intt l=tr[p].l,r=tr[p].r;if(l>=fl&&r<=fr)return tr[p].minn;intt mid=(l+r)/2,ans=-1;if(mid>=fl)ans=min(ans,findminn(p*2,fl,fr));if(mid<fr)ans=min(ans,findminn(p*2+1,fl,fr));return ans;}
	inline intt findmaxn(intt p,intt fl,intt fr){intt l=tr[p].l,r=tr[p].r;if(l>=fl&&r<=fr)return tr[p].maxn;intt mid=(l+r)/2,ans=-INF;if(mid>=fl)ans=max(ans,findmaxn(p*2,fl,fr));if(mid<fr)ans=max(ans,findmaxn(p*2+1,fl,fr));return ans;}
};
const intt mod=1e9+7;
struct treee{
	intt tr[N*4];intt n;
	inline intt lowbit(intt x){return x&(-x);}
	inline void add(intt x,intt k){for(;x<=n;x+=lowbit(x))(tr[x]+=k)%=mod;return;}
	inline intt findsum(intt x){intt ans=0;for(;x;x-=lowbit(x))(ans+=tr[x])%=mod;return ans;}
};
struct io{
	intt f[N][N];treee S;
	struct node{
		intt id,val;
		inline bool operator <(const node &n)const{return n.val>val;}
	}a[N];intt c[N];
	inline void solve(intt t){
		printf("Case #%lld: ",t);
		memset(f,0,sizeof(f));
		intt n=read(),m=read();S.n=n;
		for(int i=1;i<=n;i++){
			a[i].val=read();a[i].id=i;
		}
		sort(a+1,a+n+1);
		intt tot=1;
		a[0].val=-INF;
		for(int i=1;i<=n;i++){
			if(a[i].val==a[i-1].val)tot--;
			c[a[i].id]=++tot;
		}
		f[0][0]=1;
		for(int i=1;i<=m;i++){
			memset(S.tr,0,sizeof(S.tr));
			S.add(1,f[i-1][0]);
			for(int j=1;j<=n;j++){
				f[i][j]=S.findsum(c[j]-1);
				S.add(c[j],f[i-1][j]);
			}
		}
		intt ans=0;
		for(int i=1;i<=n;i++){
			ans+=f[m][i];ans%=mod;
		}
		print(ans,1);
		return;
	}
}T;
int main(){
	//frein();//freout();
	intt t=read();intt s=t;
	while(t--)T.solve(s-t);
    return 0;
}