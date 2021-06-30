#include<bits/stdc++.h>
using namespace std;
char n[100005];
long long x;
int mod;
int Len;
int Power(long long x,int a){//常规快速幂
	long long sum=1;
	while(a){
		if(a%2){
			sum=(x*sum)%mod;
		}
		a>>=1;
		x=(x*x)%mod;
	}
	return sum%mod;
}

int power(long long x){
	int len=Len;
	long long sum=1;
	while(len){
		if(n[len-1]-'0'){
			for(int i=0;i<(int)n[len-1]-'0';i++){
				sum=(sum*x)%mod;
			}
		}
		x=Power(x,10);
		len--;
	}
	return sum%mod;
}

//高精度减法
void sub(){
	int len=Len;
	char carry=0;
	while(len){
		n[len-1]+=carry;
		if(n[len-1]>'0'){
			n[len-1]--;
			break;
		}
		else{
			n[len-1]=9;
			carry=-1;
		}
		len--;
	}
}

int main(){
	cin >>x;
	scanf("%s",n);
	cin >>mod;
	Len=strlen(n);
	sub();
	cout <<power(x);
	return 0;
}