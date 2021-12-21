#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,m;
int arr[7003];
int dp[7005][7005];
int sum[7003];
int SUM[7003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> arr[i];
    for(int i=1; i<=n; i++) dp[3][i]=1,dp[2][i]=1;
    dp[2][0]=1;sum[0]=1;sum[1]=m;SUM[1]=1;SUM[2]=1+m;dp[1][0]=1;
    for(int i=4; i<=n+2; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dp[i][j] = ((long long)dp[i][j] + SUM[i-2] +mod - SUM[max(0,i-2-arr[j])] ) %mod;
            dp[i][j] = ((long long)dp[i][j] +mod - dp[i-2][j] + dp[max(0,i-2-arr[j])][j]) % mod;
        }
        for(int j=1;j<=m;j++)
        {
            dp[i-1][j] = ((long long)dp[i-2][j] + dp[i][j] )% mod;
        }
        for(int k=1;k<=m;k++) sum[i-2] = ((long long)sum[i-2] + dp[i][k]) % mod;
        SUM[i-1] = (SUM[i-2] + sum[i-2])%mod;
    }
    int ans=0;
    for(int i=1; i<=m; i++) ans =((long long)ans + dp[n+2][i])% mod;
    cout << ans << endl;
    return 0;
}
