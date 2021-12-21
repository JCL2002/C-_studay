#include<bits/stdc++.h>
using namespace std;
const int mod = 10000;
int n,k;
int dp[1003][1003];
int sum[1003][1003];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++) dp[i][j] = (dp[i][j] + (mod + sum[i-1][j+1] - sum[i-1][max(0,j-i+1)]))%mod;
        for(int j=1;j<=k+1;j++) sum[i][j] = (sum[i][j-1]+dp[i][j-1])%mod;
    }
    cout << dp[n][k];
    return 0;
}
