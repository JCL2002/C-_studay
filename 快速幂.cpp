#include<bits/stdc++.h>
using namespace std;
#define Type double //���庯���Ĵ���ͷ�������
Type power(Type x,unsigned long long n){//x��n�η�
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