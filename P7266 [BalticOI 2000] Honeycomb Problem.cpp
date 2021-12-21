#include<bits/stdc++.h>
using namespace std;
int n;
int arr[200][200];
int dp[200][200][2];
int mmax[200];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=n;i<=2*n-1;i++)
        for(int j=1;j<=i;j++) cin >> arr[i-n+1][j],mmax[i-n+1]=max(mmax[i-n+1],arr[i-n+1][j]);
    for(int i=2*n-2;i>=n;i--)
        for(int j=1;j<=i;j++) cin >> arr[3*n-i-1][j],mmax[3*n-i-1]=max(mmax[3*n-i-1],arr[3*n-i-1][j]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n-1;j++)
        {
            dp[i][j][0] = max(max(dp[i-1][j][0],dp[i-1][j-1][0]) + arr[i][j] , max(dp[i-1][j][1] , dp[i-1][j-1][1]) + mmax[i] );
            dp[i][j][1] = max(dp[i-1][j-1][1] , dp[i-1][j][1]) + arr[i][j];
        }
    }
    for(int i=n+1;i<=2*n-1;i++)
    {
        for(int j=1;j<=2*n-1;j++)
        {
            dp[i][j][0] = max(max(dp[i-1][j+1][0],dp[i-1][j][0]) + arr[i][j] , max(dp[i-1][j+1][1] , dp[i-1][j][1]) + mmax[i] );
            dp[i][j][1] = max(dp[i-1][j][1] , dp[i-1][j+1][1]) + arr[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans = max(ans ,max( dp[2*n-1][i][0] , dp[2*n-1][i][1] ) );
    cout << ans;
    return 0;
}
