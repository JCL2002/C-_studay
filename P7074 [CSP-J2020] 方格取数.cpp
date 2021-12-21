#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[1003][1003];
long long dp[1003][1003][3];

int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> mp[i][j];
    for(int i=0;i<=n;i++) for(int j=0;j<3;j++) dp[i][0][j] = dp[i][m+1][j] = -9999999999999ll;
    for(int i=0;i<=m;i++) for(int j=0;j<3;j++) dp[0][i][j] = dp[n+1][i][j] = -9999999999999ll;
    dp[1][0][0]=dp[0][1][0]=0;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++) dp[i][j][1] = max(dp[i][j-1][0],dp[i-1][j][1]) + mp[i][j];
        for(int i=n;i;i--) dp[i][j][2]= max(dp[i][j-1][0],dp[i+1][j][2]) + mp[i][j];
        for(int i=1;i<=n;i++) dp[i][j][0]=max(dp[i][j][1],dp[i][j][2]);
    }
    cout << dp[n][m][0] ;
    return 0;
}
