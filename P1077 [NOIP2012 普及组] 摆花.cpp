#include<bits/stdc++.h>
using namespace std;
const int mod = 1e6+7;
int dp[106][106];
int n,m;
int a[105];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m ;
    for(int i=1; i<=n; i++) cin >> a[i];
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0;j<=m;j++) dp[i][j]=dp[i-1][j];
        for(int j=1; j<=m; j++)
        {
            for(int k=1; k<=min(j,a[i]); k++) dp[i][j] =(dp[i][j] + dp[i-1][j-k]) % mod;
        }
    }
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++) cout << dp[i][j];
//        cout << endl;
//    }

    cout << dp[n][m];
    return 0;
}
