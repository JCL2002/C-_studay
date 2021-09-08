#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n>>a>>b;
		if(a==1){
			if((n-1)%b) cout <<"No"<<endl;
			else cout <<"Yes"<<endl;
			continue;
		}
		long long base=1;
		bool flag=0;
		while(base<=n){
			if((n-base)%b==0){
				flag=1;
				break;
			}
			base*=a;
//			cout <<base<<endl;
		}
		if(flag)cout <<"Yes"<<endl;
		else cout <<"No"<<endl;
	}
	return 0;
}