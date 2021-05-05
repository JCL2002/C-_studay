#include<bits/stdc++.h>
using namespace std;
unsigned long long x(unsigned long long n){
	if(n==1) return 0;
	return x((n-1)/3+1)+1;
}
int main(){
	unsigned long long n,m,k;
	cin >>n >>m;
	if(n>3*m+1){
		k=(n-3*m-1)/(2*m)+1;
		cout <<k+x(n-2*m*k);
	}
	else{
		cout <<x(n);
	}
	return 0;
}