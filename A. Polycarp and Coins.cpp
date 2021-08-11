#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >>t;
	while(t--){
		int n;
		cin >>n;
		int total=n/3;
		if(n%3==2){
			cout <<total<<' '<<total+1<<endl;
		}
		else if(n%3==1){
			cout <<total+1<<' '<<total<<endl;
		}
		else{
			cout <<total<<' '<<total<<endl;
		}
	}
	return 0;
}