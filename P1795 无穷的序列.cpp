#include<bits/stdc++.h>
using namespace std;
int find(long long n){//找到第n个元素对应的组数
	int m=(sqrt(1+8*n)-1)/2;
	if((long long)m*(m+1)/2<n){
		return m+1;
	}
	else{
		return m;
	}
}
int main(){
	int N;long long A;long long res;
	cin >>N;
	for(int i=0;i<N;i++){
		scanf("%lld",&A);
		res=(long long)find(A)-1;
		if(A-(res*(res+1)/2)-1){
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}