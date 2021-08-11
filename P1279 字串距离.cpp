#include<bits/stdc++.h>
using namespace std;
int k;
char s[2003];
char m[2003];
int dp[2003][2003];
int min(int a,int b,int c){
	if(a<=b&&a<=c) return a;
	if(b<=a&&b<=c) return b;
	return c;
}
int main(){
	cin >>s;
	cin >>m;
	int len_s=strlen(s),len_m=strlen(m);
	cin >>k;
	for(int i=0;i<=len_s;i++){//³õÊ¼»¯
		dp[i][0]=i*k;
	}
	for(int i=0;i<=len_m;i++){
		dp[0][i]=i*k;
	}
	for(int i=1;i<=len_s;i++){
		for(int j=1;j<=len_m;j++){
			dp[i][j]=min(dp[i-1][j]+k,dp[i][j-1]+k,dp[i-1][j-1]+abs((int)m[j-1]-s[i-1]));
		}
	}
	cout <<dp[len_s][len_m];
	return 0;
}