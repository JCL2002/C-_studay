#include<bits/stdc++.h>
using namespace std;
int n,t;
int s[5005],b[5005];
int dp[5005][2];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> t;
    for(int i=1; i<=n; i++) cin >> s[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) dp[i][0] = dp[i-1][0] - s[i];
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=n;j++) dp[j][i%2] = 0;
        for(int j=i; j<=n; j++)
        {
            dp[j][i%2] = max(dp[j-1][(i-1)%2]+s[j] + (i%t==0)*b[j], dp[j-1][i%2]-s[j]) ;
            if(j==n) ans=max(ans,dp[j][i%2]);
        }
    }
    cout << ans;
    return 0;
}
