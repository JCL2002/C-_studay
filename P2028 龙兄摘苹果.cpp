#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define int ull
unsigned long long n,p,k;
unsigned long long dp[1003][2];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> k >> p;
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=min((unsigned long long)i,k);j++)
        {
            dp[j][i%2] = (__int128)dp[j][(i-1)%2] *(j);
            dp[j][i%2] = (__int128)(dp[j-1][(i-1)%2]+dp[j][i%2])%p;
        }
        for(int j=0;j<=k;j++) dp[j][(i-1)%2] = 0;
    }
    cout << dp[k][n%2]%p;
    return 0;
}
