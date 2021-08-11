#include<bits/stdc++.h>
using namespace std;
#define int  long long
int dp[50][50];
int n,m;
int a,b;
bool test(int x,int y){
	if((x==a&&y==b)||(abs(x-a)+abs(y-b)==3&&abs(x-a)!=3&&abs(y-b)!=3)||x>n||y>m)return 0;
	return 1;
}
signed main(){
	cin >>n>>m;
	
	cin >>a>>b;
	dp[0][0]=1;
	for(int i=0;i<=n+m;i++){
		for(int j=0;j<=i;j++){
			int x=i-j;
			int y=j;
			if(test(x,y)){
				if(test(x+1,y)) dp[x+1][y]+=dp[x][y];
				if(test(x,y+1)) dp[x][y+1]+=dp[x][y];
			}
		}
	}
//	cout <<endl;
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=m;j++){
//			cout <<dp[i][j]<<" ";
//		}
//		cout <<endl;
//	}
	cout <<dp[n][m];
	return 0;
}