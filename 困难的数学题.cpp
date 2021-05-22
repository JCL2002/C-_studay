#include<bits/stdc++.h>
using namespace std;
unsigned long long A(unsigned long long n,unsigned long long m){
	unsigned long long sum=1;
	for(unsigned long long i=0;i<m;i++){
		sum=(sum*n)%100000007;
		n--;
	}
	return sum;
}
int main(){
	unsigned int n,k,times,remain;
	unsigned long long sum=0,S=0;
	cin >>n>>k;
	times=n/k;
	for(unsigned int i=1;i<=times;i++){
		remain=n-i*(k-1);
		S=A((unsigned long long)remain-1,(unsigned long long)i-1)/A((unsigned long long)i-1,(unsigned long long)i-1);

		sum=(sum+S)%100000007;
	}
	cout <<sum;
	return 0;
}