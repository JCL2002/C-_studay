#include<bits/stdc++.h>
using namespace std;
/*
����1ʱ
n=(m+sqrt(5*m*m+4))/2
*/
/*
����-1ʱ
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
		if((n*n-m*n-m*m)==1){//��������ʱ
			if(n>N) N=n;
			if(m>M) M=m;
			//��Ϊ�ǵ����������n*n+m*m����
		}
		if((_n*_n-_n*m-m*m)==-1){
			if(_n>N) N=_n;
			if(m>M) M=m;;
			//��Ϊ�ǵ����������n*n+m*m����
		}
	}
	cout<< "m="<<M<<endl<<"n="<<N;
	return 0;
}