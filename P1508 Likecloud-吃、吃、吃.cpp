#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,dp[204][204],mp[204][204];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m; //n ÐÐ m ÁÐ
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> mp[i][j];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m+1; j++)
            dp[i][j]=-1000000000000;
    for(int i=n; i>0; i--)
    {
        for(int j=max(1ll,(m+1)/2-(n-i+1)); j<=min(m,(m+1)/2+(n-i+1)); j++)
        {
            dp[i][j] = max( max(dp[i+1][j-1], dp[i+1][j+1]), dp[i+1][j] ) + mp[i][j];
        }
    }
    int ans=0;
    for(int i=1; i<=m; i++) ans=max(ans,dp[1][i]);
    cout << ans;
    return 0;
}
