#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[1003][1003];
int d[1003],c[1003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> d[i] ;
    for(int i=1;i<=m;i++) cin >> c[i] ;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=m;j++)
        {
            dp[i][j]= dp[i-1][j-1]+(long long)d[i]*c[j];
            if(j>i) dp[i][j] = min(dp[i][j],dp[i][j-1]);
        }
    }
    long long ans=999999999999999ll;
    for(int i=n;i<=m;i++) ans=min(ans,dp[n][i]);
    cout << ans;
    return 0;
}
