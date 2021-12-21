#include<bits/stdc++.h>
using namespace std;
double dp[1255][1255];
int n;
int main()
{
    cin >> n;
    n/=2;
    for(int i=2;i<=n;i++) dp[i][0]=1.0,dp[0][i]=1.0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dp[i][j]=(dp[i-1][j]+dp[i][j-1])/2;
    printf("%.4lf",dp[n][n]);
    return 0;
}
