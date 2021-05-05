#include<bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long x,unsigned int m,unsigned int p){
	unsigned long long res=1;
	while(m){
		if(m&1) res=(res*x)%p;
		x=(x*x)%p;
		m>>=1;
	}
	return res%p;
}