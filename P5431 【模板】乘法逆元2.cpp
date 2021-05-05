#include<bits/stdc++.h>
using namespace std;
unsigned int a[1000000];
unsigned long long power(unsigned long long x,unsigned int m,unsigned int p){
	unsigned long long res=1;
	while(m){
		if(m&1) res=(res*x)%p;
		x=(x*x)%p;
		m>>=1;
	}
	return res%p;
}
int main(){
	unsigned int n,p,k;
	cin >>n>>p>>k;
	for(register unsigned int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	register unsigned int sum=0;
	for(register unsigned int i=0;i<n;i++){
		sum=(sum+power((unsigned long long)k,i,p)/power((unsigned long long)a[i],p-2,p));
		
	}
	cout <<sum;
	return 0;
}