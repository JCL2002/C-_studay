#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		long long l,r;
		cin >>l>>r;
		long long sum=0ll;
		while(r){
			sum+=(r-l);
			r/=10;
			l/=10;
		}
		cout <<sum<<endl;
	}
	return 0;
}