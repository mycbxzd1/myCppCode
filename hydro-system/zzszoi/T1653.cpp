#include<bits/stdc++.h>
using namespace std;
int b,a,ans,x,y,c[760]={1,1};
int pow(int b,int p,int k){
    ans=1;
    while(p)
    {
        if(p&1){ans=(ans*b)%k;}
        b=b*b%k,p>>=1;
    }
    return ans;
}
void print(int p[])
{
    printf("%d",p[p[0]]);
    for(int i=p[0]-1;i>=1;i--){printf("%d%d%d%d",p[i]/1000,p[i]/100%10,p[i]/10%10,p[i]%10);}
    return;
}
void C(int n,int m){
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=c[0];i++)c[i]*=(n-k+1);
        for(int i=1;i<=c[0];i++)c[i+1]+=c[i]/10000,c[i]%=10000;
        while(c[c[0]+1])c[0]++;
        for(int i=c[0],y=0;i>=1;i--)y=y*10000+c[i],c[i]=y/k,y%=k;
        while(!c[c[0]])c[0]--;
    }
}
int main()
{
    cin>>b>>a;
    a%=1000,a=pow(a,a,1000)-1,b--;
    C(a,b);
    print(c);
    return 0;
}