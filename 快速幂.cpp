#include<bits/stdc++.h>
using namespace std;
#define Type unsigned long long //���庯���Ĵ���ͷ�������
Type power(Type x,unsigned long long n){//x��n�η�
	Type res=1;
	while(n){
		if(n&1) res*=x;
		x*=x;
		n>>=1;
	}
	return res;
}
