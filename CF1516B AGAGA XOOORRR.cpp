#include<bits/stdc++.h>
using namespace std;
long long dp[2003][2003];
long long arr[2003];
int main(){
	int t;cin >>t;
	while(t--){
		int n;
		cin >>n;
		for(int i=1;i<=n;i++)cin >>arr[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[i][j]=dp[i][j-1]^arr[j];
			}
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(dp[1][i]==dp[i+1][n]){
				flag=1;
				break;
			}
			for(int j=i+1;j<n;j++){
				if(dp[1][i]==dp[i+1][j]&&dp[i+1][j]==dp[j+1][n]){
					flag=1;
					break;
				}
			}
		}
		if(flag) cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
	}
	return 0;
}