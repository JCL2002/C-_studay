#include<bits/stdc++.h>
using namespace std;
int dp[201][7];//动态规划数组
int main(){
	int n,k;
	cin >>n >>k;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i>=j){
				dp[i][j]=dp[i-j][j]+dp[i-1][j-1];//状态转移方程
				//可以理解为存在1和不存在1的情况
			}
		}
	}
	cout << dp[n][k];
	return 0;
}