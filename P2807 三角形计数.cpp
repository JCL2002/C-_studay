#include<bits/stdc++.h>
using namespace std;
int up(int i,int j){//第i行大小为j的向上的三角形数量
	int k=i-(j-1);
	if(k>0){
		return k;
	}
	return 0;
}
int down(int i,int j){//第i行大小为j的向下的三角形数量
	int k=i-(2*j-1);
	if(k>0){
		return k;
	}
	return 0;
}
int main(){
	unsigned int t,n;
	unsigned long long sum;
	cin >>t;
	for(unsigned int k=0;k<t;k++){
		cin >>n;
		sum=0;
		for(unsigned int i=1;i<=n;i++){
			for(unsigned int j=1;j<=i;j++){
				sum=sum+up(i,j)+down(i,j);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}