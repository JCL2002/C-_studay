#include<iostream>
using namespace std;
const int mod=1000000007;
struct matrix{
	int size;//矩阵大小
	int mar[102][102];//矩阵
};
int n; long long k;
matrix A,E;
matrix ti(matrix a,matrix b){//矩阵ax矩阵b
	int n=a.size;
	if(a.size!=b.size)return E;
	matrix res;
	res.size=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int sum=0;
			//第i行j列
			for(int k=1;k<=n;k++){
				sum=(sum%mod+(long long)a.mar[i][k]*b.mar[k][j]%mod)%mod;
			}
			res.mar[i][j]=sum;
		}
	}
	return res;
}
matrix power(matrix x,long long n){
	matrix res=E;
	while(n){
		if(n%2)res=ti(res,x);
		x=ti(x,x);
		n>>=1;
	}
	return res;
}
void init(){//初始化单位单位矩阵
	E.size=n;
	for(int i=1;i<=n;i++){
		E.mar[i][i]=1;
	}
}
int main(){
	cin >>n>>k;
	A.size=n;
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//第i行j列
			cin >>A.mar[i][j];
		}
	}
	A=power(A,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout <<A.mar[i][j]<<' ';
		}
		cout <<endl;
	}
	return 0;
}