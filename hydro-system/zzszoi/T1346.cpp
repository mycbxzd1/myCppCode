#include<bits/stdc++.h>
using namespace std;

class two_matrix{
private:
    vector<vector<long long>>value;
public:
    two_matrix(int n,int m){value.resize(n,vector<long long>(m));}
    long long get(int i,int j)const{return value[i][j];}
    void set(int i,int j,long long v){value[i][j]=v;}
    int rows()const{return value.size();}
    int cols()const{return value.empty()?0:value[0].size();}
    two_matrix operator*(const two_matrix&other)const{
        int n=rows(),m=other.cols(),p=cols();
        two_matrix res(n,m);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<p;k++){
            res.value[i][j]=(res.value[i][j]+value[i][k]*other.value[k][j])%m;
        }
        return res;
    }
    static two_matrix power(const two_matrix&base,int exp,int mod){
        int n=base.rows();
        two_matrix res(n,n);
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

int n,m;

long long get_S(int n){
    two_matrix A(3,3);
    A.set(0,0,2);A.set(0,1,0);A.set(0,2,-1);
    A.set(1,0,1);A.set(1,1,0);A.set(1,2,0);
    A.set(2,0,0);A.set(2,1,1);A.set(2,2,0);

    vector<long long>S={2,1,0};
    A=two_matrix::power(A,n,m);

    vector<long long>res(3,0);
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        res[i]=(res[i]+S[j]*A.get(i,j))%m;
    }
    return res[2];
}

long long get_G(int n){
    two_matrix A(4,4);
    A.set(0,0,3);A.set(0,1,-2);A.set(0,2,-1);A.set(0,3,1);
    A.set(1,0,1);A.set(1,1,0);A.set(1,2,0);A.set(1,3,0);
    A.set(2,0,0);A.set(2,1,1);A.set(2,2,0);A.set(2,3,0);
    A.set(3,0,0);A.set(3,1,0);A.set(3,2,1);A.set(3,3,0);

    vector<long long>G={7,3,1,0};
    A=two_matrix::power(A,n,m);

    vector<long long>res(4,0);
    for(int i=0;i<4;i++)for(int j=0;j<4;j++){
        res[i]=(res[i]+G[j]*A.get(i,j))%m;
    }
    return res[3];
}

int main(){
    cin>>n>>m;
    long long S=get_S(n),G=get_G(n-1);
    cout<<((n*S-G)%m+m)%m<<endl;
    return 0;
}
