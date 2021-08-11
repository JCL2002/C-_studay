#include<bits/stdc++.h>
using namespace std;
long long up(long long d,long long x){
	long long res=d/x;
	if(res*x<d) return res+1;
	return res;
}
int main(){
	int t;cin >>t;
	while(t--){
		long long n,d;
		cin >>n>>d;
		long long x;
		x=sqrt(d);
		if(x+up(d,x)-1<=n||x+1+up(d,x+1)-1<=n){
			cout <<"YES"<<endl;
		}
		else{
			cout <<"NO"<<endl;
		}
	}
	return 0;
}