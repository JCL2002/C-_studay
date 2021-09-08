#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin >>t;
	while(t--){
		int n;
		cin >>n;
		int before=0,current=0;
		long long ans=0;
		while(n--){
			cin >>current;
			ans=max((double)ans,(double)max(before,current)*min(before,current));
			before=current;
		}
		cout <<ans<<endl;
	}
	return 0;
}