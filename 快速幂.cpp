#include<bits/stdc++.h>
using namespace std;
#define Type double //定义函数的传入和返回类型
Type power(Type x,unsigned long long n){//x的n次方
	Type res=1;
	while(n){
		if(n&1) res*=x;
		x*=x;
		n>>=1;
	}
	return res;
}
int main(){
	Type a;unsigned long long b;
	cin >>a >>b;
	cout <<power(a,b);
	return 0;
}