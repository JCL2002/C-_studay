#include<bits/stdc++.h>
using namespace std;
int arr[1003][1003];
int dp[1003][1003];
int main(){
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin >>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
		}
	}
	int M=0;
	for(int i=1;i<=n;i++){
		M=max(M,dp[n][i]);
	}
	cout <<M;
	return 0;
}