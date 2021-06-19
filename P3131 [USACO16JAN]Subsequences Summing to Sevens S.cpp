#include<bits/stdc++.h>
using namespace std;
long long sum[50002];//前缀和数组
int main(){
	int n;cin >>n;int tmp;
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		sum[i]=sum[i-1]+tmp;
	}
	for(int i=n;i>0;i--){//区间长度
		for(int j=1;j+i-1<=n;j++){//区间起始点
			long long S=sum[j+i-1]-sum[j-1];
			if(S%7==0){
				cout <<i;
				return 0;
			}
		}
	}
	cout <<0;
	return 0;
}
//开启O2优化之后能通过
/*
正解思路，代码就懒得写了……
假如两个数相减对7取模等于0，因此在计算前缀和数组的时候直接对7取模
那么这两个数对7的余数一定相等
而对7的余数为0-6，直接枚举每一种模数即可
*/