#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int mp[103][103];
set<int> dp[103][103];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> p;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> mp[i][j] ;
    dp[1][1].insert(mp[1][1]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(auto x : dp[i][j-1]) dp[i][j].insert(x*mp[i][j]%p);
            for(auto x : dp[i-1][j]) dp[i][j].insert(x*mp[i][j]%p);
        }
    }
    cout << dp[n][m].size() << endl;
    for(auto x : dp[n][m]) cout << x << " ";
    return 0;
}
