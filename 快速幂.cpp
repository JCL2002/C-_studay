#include<bits/stdc++.h>
using namespace std;
#define Type unsigned long long //定义函数的传入和返回类型
Type power(Type x,unsigned long long n){//x的n次方
	Type res=1;
	while(n){
		if(n&1) res*=x;
		x*=x;
		n>>=1;
	}
	return res;
}
