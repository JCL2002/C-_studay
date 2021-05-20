#include<bits/stdc++.h>
using namespace std;
int type[15];//硬币面值类型
int Min[900001];
int last[900001];//最后一个硬币
int main(){
	int k,n;
	cin >>k>>n;//分别输入硬币价值数和目标价钱
	for(int i=0;i<k;i++){
		cin >>type[i];
	}
	//数组初始化
	for(int i=1;i<=n;i++){
		Min[i]=900000000;
	}
	//动态规划
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			if(j>=type[i]){//当可以用type[i]的货币支付时，判断用不用
				if(Min[j-type[i]]+1<Min[j]){
					Min[j]=Min[j-type[i]]+1;
					last[j]=type[i];//记录最后一个
				}
			}
		}
	}
	cout <<"一共用"<<Min[n]<<"个"<<endl;
	cout <<"硬币回溯："<<endl;
	while(n){
		cout <<last[n]<<endl;
		n-=last[n];
	}
	return 0;
}
