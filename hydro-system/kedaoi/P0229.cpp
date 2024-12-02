#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,a[100100];
 
bool valid(int x){
    int last=0,group=0;
    for(i=1;i<=n+1;++i)
        if(a[i]-a[last]>=x)last=i;
        else group++;
    if(group<=m)return true;
    else return false;
}
int main(){
    scanf("%d%d%d",&k,&n,&m);
    a[0]=0;a[n+1]=k;
    for(i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a,a+n);
    int l=1,r=k;
    while(l<r){
        int mid=(l+1+r)/2;
        if(valid(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}