#include<bits/stdc++.h>
using namespace std;

class two_matrix{
private:
    vector<vector<int>>value;
public:
    two_matrix(int n,int m){value.resize(n,vector<int>(m));}
    int get(int i,int j){return value[i][j];}
    void set(int i,int j,int v){value[i][j]=v;}
    int rows()const{return value.size();}
    int cols()const{return value.empty()?0:value[0].size();}
    two_matrix operator+(const two_matrix&other){
        int n=rows(),m=cols();
        two_matrix res(n,m);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)res.value[i][j]=value[i][j]+other.value[i][j];
        return res;
    }
    two_matrix operator-(const two_matrix&other){
        int n=rows(),m=cols();
        two_matrix res(n,m);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)res.value[i][j]=value[i][j]-other.value[i][j];
        return res;
    }
    two_matrix operator*(const two_matrix&other){
        int n=rows(),m=other.cols(),p=cols();
        two_matrix res(n,m);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<p;k++){
            res.value[i][j]+=value[i][k]*other.value[k][j];
        }
        return res;
    }
    static two_matrix power(const two_matrix&base,int exp){
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

int main(){
    two_matrix mat1(2,2),mat2(2,2);

    // 初始化矩阵mat1
    mat1.set(0,0,1); mat1.set(0,1,2);
    mat1.set(1,0,3); mat1.set(1,1,4);

    // 初始化矩阵mat2
    mat2.set(0,0,5); mat2.set(0,1,6);
    mat2.set(1,0,7); mat2.set(1,1,8);

    // 矩阵加法
    two_matrix result=mat1+mat2;
    cout<<result.get(0,0)<<" "<<result.get(0,1)<<"\n"; // 输出第一行结果
    cout<<result.get(1,0)<<" "<<result.get(1,1)<<"\n"; // 输出第二行结果

    // 矩阵乘法
    result=mat1*mat2;
    cout<<result.get(0,0)<<" "<<result.get(0,1)<<"\n"; // 输出第一行结果
    cout<<result.get(1,0)<<" "<<result.get(1,1)<<"\n"; // 输出第二行结果

    // 矩阵快速幂
    result=two_matrix::power(mat1,2);
    cout<<result.get(0,0)<<" "<<result.get(0,1)<<"\n"; // 输出第一行结果
    cout<<result.get(1,0)<<" "<<result.get(1,1)<<"\n"; // 输出第二行结果

    return 0;
}
