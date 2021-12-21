#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[12][100005];
int dp[100005][5];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    if(n<3||m<3)
    {
        cout << -1 ;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> arr[i][j] ;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) dp[i][0] += arr[j][i];
    dp[1][4]=dp[1][3]=dp[1][2]=dp[1][1]=-1000000000;
    for(int i=2;i<=m;i++)
    {
        dp[i][4] = max(dp[i-1][3],dp[i-1][2]) + dp[i][0];
        dp[i][3] = max(dp[i-1][3],dp[i-1][2]) + dp[i][0];
        dp[i][2] = max(max(dp[i-1][2],dp[i-1][1]),dp[i-1][0]) + arr[1][i] + arr[n][i];
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]) + dp[i][0];
    }
    int mmax = -1000000000;
    for(int i=3;i<=m;i++) mmax=max(mmax,dp[i][4]);
    cout << mmax;
    return 0;
}
