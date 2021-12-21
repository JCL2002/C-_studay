#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[103][103];
pair<int,int> arr[103];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=min(i,n-k);j++)
        {
            dp[i][j] = dp[i-1][j-1] + abs(arr[i].second-arr[i-1].second);
            for(int l=j-1;l<i;l++) dp[i][j] = min(dp[i][j],dp[l][j-1]+abs(arr[i].second-arr[l].second));
        }
    }
    int ans=100000000;
    for(int i=n-k;i<=n;i++) ans = min(ans,dp[i][n-k]);
    cout << ans;
    return 0;
}
