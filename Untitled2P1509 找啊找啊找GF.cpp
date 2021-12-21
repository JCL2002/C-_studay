#include<bits/stdc++.h>
using namespace std;
pair<int,int> dp[103][103];
int n,m,r;
int Time[103];
int cost[103];
int rp[103];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> cost[i] >> rp[i] >> Time[i];
    }
    cin >> m >> r;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=cost[i];j--)
        {
            for(int k=r;k>=rp[i];k--)
            {
                if(dp[j][k].first < dp[j-cost[i]][k-rp[i]].first+1) dp[j][k].first = dp[j-cost[i]][k-rp[i]].first +1,dp[j][k].second =  dp[j-cost[i]][k-rp[i]].second + Time[i];
                else if(dp[j][k].first == dp[j-cost[i]][k-rp[i]].first+1) dp[j][k].second = min( dp[j][k].second , dp[j-cost[i]][k-rp[i]].second + Time[i] );
            }
        }
    }
    int mmax=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=r;j++) mmax=max(mmax,dp[i][j].first);
    int mmin=0x3f3f3f3f;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=r;j++) if(dp[i][j].first==mmax) mmin=min(mmin,dp[i][j].second);
    cout << mmin;
    return 0;
}
