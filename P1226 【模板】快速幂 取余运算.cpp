#include<bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long x,unsigned long long a, unsigned long long k){//x^a¶ÔkÈ¡Ä£
	long long res=1;
	while(a){
		if(a&1)res=(res%k*x%k)%k;
		x=(x%k*x%k)%k;
		a>>=1;
	}
	return res%k;
}
int main(){
	unsigned long long b,p,k;
	cin >>b>>p>>k;
	cout <<b<<'^'<<p<<" mod "<<k<<'='<<power(b,p,k);
	return 0;
}