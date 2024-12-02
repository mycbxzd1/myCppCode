#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int n,a[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll pos=0,neg=0;
    for(int i=n;i>=2;i--){
        a[i]-=a[i-1];
        if(a[i]>0)pos+=a[i];
        else neg-=a[i];
    }
    cout<<max(pos,neg)<<endl;
    cout<<abs(pos-neg)+1<<endl;
    return 0;
}
/*
 * 考虑差分，求出a的差分数组b，
 * 题目对a的区间修改操作，相当于每次可以从b中选出两个数，一个加1，另一个减1，
 * 目标是使得b2,...,bn全部变为0，最终得到的数列a就是n个b1
 *
 * 从b中选两个数，分情况讨论：
 * 1. 选bi和bj，这种操作会改变b2,...,bn中两个数的值，
 *    应该在保证bi和bj一正一负的情况下尽量多地采取这种操作，快速地接近目标
 * 2. 选b1和bj
 * 3. 选bi和b(n+1)
 * 4. 选b1和b(n+1)，这种操作不改变b2,...,bn的值，是一个无效操作
 *
 * 设b2,...,bn中正数的总和为p，负数的总和为q。
 * 首先要以正负配对的方式尽量执行第1类操作，可执行min(p,q)次.
 * 剩余|p-q|个未配对，每次可以选b1或b(n+1)进行配对，共需|p-q|次。
 *
 * 因此，最少操作次数为 min(p,q) + |p-q| 次，即 max(p,q) 次;
 *      根据|p-q|次第2、3类操作的选择情况，能产生 |p-q|+1 中不同的b1的值
 */