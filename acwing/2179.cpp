#include <bits/stdc++.h>
using namespace std;

const int N=430,M=(150*270+N)*2,INF=1e8;
int m,n,S,T,h[N],e[M],f[M],ne[M],idx,q[N],d[N],cur[N];

auto bfs=[]()->bool
{
    int hh=0,tt=0;
    memset(d,-1,sizeof d);
    q[0]=S,d[S]=0,cur[S]=h[S];
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];~i;i=ne[i])
        {
            int ver=e[i];
            if(d[ver]==-1&&f[i])
            {
                d[ver]=d[t]+1;
                cur[ver]=h[ver];
                if(ver==T) return 1;
                q[++tt]=ver;
            }
        }
    }
    return 0;
};

int dfs(int u,int limit)
{
    if(u==T) return limit;
    int flow=0;
    for(int i=cur[u];~i&&flow<limit;i=ne[i])
    {
        cur[u]=i;
        int ver=e[i];
        if(d[ver]==d[u]+1&&f[i])
        {
            int t=dfs(ver,min(f[i],limit-flow));
            if(!t) d[ver]=-1;
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

auto dinic=[]()
{
    int r=0,flow;
    while(bfs()) while(flow=dfs(S,INF)) r+=flow;
    return r;
};

int main()
{
    auto add=[&](int a,int b,int c)
    {
        e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
        e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
    };
    cin.tie(0)->sync_with_stdio(0);
    cin>>m>>n,S=0,T=m+n+1;
    memset(h,-1,sizeof h);
    int tot=0;
    for(int i=1,c;i<=m;i++)
        cin>>c,add(S,i,c),tot+=c;
    for(int i=1,c;i<=n;i++)
        cin>>c,add(m+i,T,c);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            add(i,m+j,1);
    if(dinic()!=tot)
        cout<<"0\n";
    else
    {
        cout<<"1\n";
        for(int i=1;i<=m;i++)
        {
            for(int j=h[i];~j;j=ne[j])
                if(e[j]>m&&e[j]<=m+n&&!f[j])
                    cout<<e[j]-m<<' ';
            cout<<'\n';
        }
    }
}
