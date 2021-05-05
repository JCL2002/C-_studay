#include<bits/stdc++.h>
using namespace std;
/*
等于1时
n=(m+sqrt(5*m*m+4))/2
*/
/*
等于-1时
n=(m+sqrt(5*m*m-4))/2
*/
long long N,M;
int main(){
	unsigned long long k;
	cin >>k;
	for(unsigned long long m=1;m<=k;m++){
		unsigned long long n,_n;
		_n=(m+sqrt(5*m*m-4))/2;
		n=(m+sqrt(5*m*m+4))/2;
		if(n>k&&_n>k){
			break;
		}
		if((n*n-m*n-m*m)==1){//满足条件时
			if(n>N) N=n;
			if(m>M) M=m;
			//因为是单调递增因此n*n+m*m递增
		}
		if((_n*_n-_n*m-m*m)==-1){
			if(_n>N) N=_n;
			if(m>M) M=m;;
			//因为是单调递增因此n*n+m*m递增
		}
	}
	cout<< "m="<<M<<endl<<"n="<<N;
	return 0;
}