#include<bits/stdc++.h>
using namespace std;
int dp[550005],n,m,w[102],c[102];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> c[i] >> w[i];
    for(int i=1;i<=m+5000;i++) dp[i]=0x5f5f5f5f;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<c[i];j++) dp[j]=min(dp[j],w[i]);
        for(int j=c[i];j<=m+5000;j++) dp[j]=min(dp[j],dp[j-c[i]]+w[i]);
//        cout << "debug " << dp[i] << endl;
    }
    int mmin=0x5f5f5f5f;
    for(int i=m;i<=m+5000;i++)mmin=min(mmin,dp[i]);
    cout << mmin;
    return 0;
}
