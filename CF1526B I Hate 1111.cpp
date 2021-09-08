#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		int num=n/111;
		n%=11;
		if(num>=n)cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
	}
	return 0;
}