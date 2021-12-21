#include<bits/stdc++.h>
using namespace std;
int n,h;
int f[30],d[30],t[30];
int sum[30];
long long dp[30][200];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> h;
    h*=12;
    for(int i=1;i<=n;i++) cin >> f[i];
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=1;i<n;i++) cin >>t[i];
    for(int i=2;i<=n;i++) sum[i] = sum[i-1]+t[i-1];
    for(int i=1;i<=n;i++)
        for(int j=sum[i];j<=h;j++)
            for(int k=0;k<=j-sum[i]&&(k-1)*d[i]<=f[i];k++)
                dp[i][j] = max(dp[i][j],dp[i-1][j-k-t[i-1]]+f[i]*k-(k)*(d[i]*(k-1))/2);
    long long ans=0;
    for(int i=1;i<=n;i++) ans = max(ans,dp[i][h]);
    cout << ans;
    return 0;
}
