#include<bits/stdc++.h>
using namespace std;
bool mp[1505][1505];
int dp[1505][1505];
int n,m;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(register int j=1; j<=m; j++)
            cin >> mp[i][j],dp[i][j]=1;
    for(int i=2; i<=n; i++)
        for(register int j=2; j<=m; j++)
            if(mp[i][j]==mp[i-1][j-1] && mp[i][j]!=mp[i-1][j] && mp[i][j]!=mp[i][j-1]) dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
    int mmax=0;
    for(int i=2; i<=n; i++)
        for(register int j=2; j<=m; j++) mmax=max(mmax,dp[i][j]);
    cout << mmax << endl;
    return 0;
}
