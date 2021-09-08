#include<bits/stdc++.h>
using namespace std;
int dp[41][41][41][41];
int one,two,three,four;
int n,m;
int val[355];
int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>val[i];
	}
	for(int i=1;i<=m;i++){
		int  tmp;
		cin >>tmp;
		if(tmp==1) one++;
		if(tmp==2) two++;
		if(tmp==3) three++;
		if(tmp==4) four++;
	}
	for(int i=0;i<=one;i++){
		for(int j=0;j<=two;j++){
			for(int k=0;k<=three;k++){
				for(int l=0;l<=four;l++){
					if(i) dp[i][j][k][l]=max(dp[i-1][j][k][l],dp[i][j][k][l]);
					if(j) dp[i][j][k][l]=max(dp[i][j-1][k][l],dp[i][j][k][l]);
					if(k) dp[i][j][k][l]=max(dp[i][j][k-1][l],dp[i][j][k][l]);
					if(l) dp[i][j][k][l]=max(dp[i][j][k][l-1],dp[i][j][k][l]);
					dp[i][j][k][l]+=val[i+2*j+3*k+4*l+1];
				}
			}
		}
	}
	cout <<dp[one][two][three][four];
	return 0;
}