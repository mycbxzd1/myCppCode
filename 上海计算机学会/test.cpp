#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,q,a[N],rank_a[N];

// Fenwick Tree (BIT) for range queries
int bit[N];
void update(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=idx&-idx;
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=idx&-idx;
    }
    return sum;
}

int find_mex(set<int>&st){
    for(int i=0;;i++){
        if(!st.count(i))return i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];

    // Calculate ranks
    vector<int>sorted_a(a+1,a+n+1);
    sort(sorted_a.begin(),sorted_a.end());
    for(int i=1;i<=n;i++){
        rank_a[i]=lower_bound(sorted_a.begin(),sorted_a.end(),a[i])-sorted_a.begin()+1;
    }

    while(q--){
        int k,r;
        cin>>k>>r;

        set<int>removed_from_left,removed_from_right;
        for(int i=1;i<k;i++)removed_from_left.insert(rank_a[i]);
        for(int i=k+1;i<=n;i++)removed_from_right.insert(rank_a[i]);

        int mex_left=find_mex(removed_from_left);
        int mex_right=find_mex(removed_from_right);

        int x=max(mex_left,mex_right)>=r?0:max(r-mex_left,r-mex_right);
        cout<<x<<"\n";
    }

    return 0;
}
