#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[1000006];
int dp[1000006][2];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=2;i<=n+2;i++)
    {
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+arr[i-1];
        dp[i][0]=min(dp[i-1][1],dp[i-2][1]);
    }
    cout << min(min(dp[n+2][0],dp[n+2][1]) , min(dp[n+1][0],dp[n+1][1]) ) << endl;;
//    for(int i=1;i<=n+2;i++) cout << dp[i][0] << " " << dp[i][1] << endl;
    return 0;
}
