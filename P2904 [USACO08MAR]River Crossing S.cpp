#include<bits/stdc++.h>
using namespace std;
int dp[2503][2503];
int ans[2503];
int cost[2503];
int n,tmp;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> cost[0];
    for(int i=1;i<=n;i++) cin >> tmp,cost[i]=cost[i-1]+tmp;
    for(int i=1;i<=n;i++) dp[0][i]=cost[i];
    ans[1]=cost[1];
    for(int i=2;i<=n;i++)
    {
        ans[i]=cost[i];
        for(int j=1;j<i;j++)
        {
            dp[j][i]=ans[i-j]+cost[j]+cost[0];
            ans[i]=min(ans[i],dp[j][i]);
        }
    }
    cout << ans[n];
    return 0;
}
