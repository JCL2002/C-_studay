#include<bits/stdc++.h>
using namespace std;
vector<int>I[3000006];
int dp[3000006];
int n;
int main(){
	cin >>n;
	int mmax=0;
	for(int i=1;i<=n;i++){
		int left,right;
		scanf("%d %d",&left,&right);
		I[right+1].push_back(left+1);
		mmax=max(mmax,right+1);
	}
	for(int i=1;i<=mmax;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<(int)I[i].size();j++){
			dp[i]=max(dp[i],dp[I[i][j]-1]+(i-I[i][j]+1));
		}
//		cout <<dp[i]<<" ";
	}
//	for(int i=0;i<=mmax;i++);
	cout <<dp[mmax];
	return 0;
}