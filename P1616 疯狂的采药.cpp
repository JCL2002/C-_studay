#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[10000007];
int t,m;
int c[10004];
int w[10004];
signed main()
{
    cin >> t >> m;
    for(int i=1;i<=m;i++) cin >> w[i] >> c[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=w[i];j<=t;j++) dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    }
    cout << dp[t];
    return 0;
}
