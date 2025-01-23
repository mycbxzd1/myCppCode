#include<bits/stdc++.h>
using namespace std;
class two_matrix{
private:
    vector<vector<int>>value;
    int mod;
public:
    two_matrix(int n,int m,int mod):mod(mod){value.resize(n,vector<int>(m));}
    int get(int i,int j){return value[i][j];}
    void set(int i,int j,int v){value[i][j]=v%mod;}
    int rows()const{return value.size();}
    int cols()const{return value.empty()?0:value[0].size();}
    two_matrix operator*(const two_matrix&other){
        int n=rows(),m=other.cols(),p=cols();
        two_matrix res(n,m,mod);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<p;k++){
            res.value[i][j]=(res.value[i][j]+1LL*value[i][k]*other.value[k][j])%mod;
        }
        return res;
    }
    static two_matrix power(const two_matrix&base,int exp,int mod){
        int n=base.rows();
        two_matrix res(n,n,mod);
        for(int i=0;i<n;i++)res.set(i,i,1);
        two_matrix current=base;
        while(exp){
            if(exp&1)res=res*current;
            current=current*current;
            exp>>=1;
        }
        return res;
    }
};

int main(){
    int n,p;cin>>n>>p;
    if(n==0){cout<<0%p<<endl;return 0;}
    if(n==1){cout<<1%p<<endl;return 0;}
    two_matrix a(2,2,p);
    a.set(0,0,1);a.set(0,1,1);
    a.set(1,0,1);a.set(1,1,0);
    two_matrix res=two_matrix::power(a,n-1,p);
    cout<<res.get(0,0)<<endl;
    return 0;
}
