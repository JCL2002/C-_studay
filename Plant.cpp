#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long power(long long x,unsigned long long n){
	long long res=1;
	while(n){
		if(n%2) res=(res%mod*x%mod)%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return res;
}
int main(){
	unsigned long long n;
	cin >>n;
	if(n==0)cout <<1;
	else cout <<(power(2ll,2*n-1)%1000000007+power(2ll,n-1)%1000000007)%1000000007;
	return 0;
}