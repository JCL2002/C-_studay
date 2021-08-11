#include<bits/stdc++.h>
using namespace std;
long long arr[105];
int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>arr[i];
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(arr[i]<i-1){
				flag=false;
//				cout <<"i:"<<i<<":"<<arr[i]<<endl;
				cout <<"NO"<<endl;
				break;
			}
			else{
				long long k=arr[i]-i+1;
				arr[i+1]+=k;
			}
		}
		if(flag) cout <<"YES"<<endl;
	}
	return 0;
}