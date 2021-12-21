#include<bits/stdc++.h>
using namespace std;
bool mp[1003][1003];
int dp[1003][1003];
int n,t,x,y;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> x >>y;
        mp[x][y] = 1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!mp[i][j])dp[i][j] = min( min(dp[i-1][j],dp[i][j-1]) , dp[i-1][j-1] ) +1;
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
