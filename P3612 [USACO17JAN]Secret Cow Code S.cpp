#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
char s[31];
int len;
char dg(ll n){
	if(n<=len){
		return s[n-1];
	}
	else{
		ll t=1;
		while(len*t<n){
			t<<=1;
		}
		t>>=1;
		if(n%(len*t)==1){
			return dg(n-1);
		}
		else{
			return dg(n-1-(len*t));
		}
	}
}
int main(){
	cin >>s >>N;
	len=strlen(s);
	cout <<dg(N);
	return 0;
}