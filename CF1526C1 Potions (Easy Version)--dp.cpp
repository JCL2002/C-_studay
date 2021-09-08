#include<bits/stdc++.h>
using namespace std;
long long arr[2003];
long long dp[2003][2003];
int main(){
	int n ;cin >>n;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=0;
		for(int j=1;j<=i;j++){
			if(dp[i-1][j-1]+arr[i]>=0&&dp[i-1][j-1]!=-1){
				dp[i][j]=max(dp[i-1][j-1]+arr[i],dp[i-1][j]);
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++)cout <<dp[i][j]<<" ";
//		cout <<endl;
//	}
	for(int i=0;i<n;i++){
		if(dp[n][i+1]<0){
			cout <<i;
			return 0;
		}
	}
	cout <<n;
}