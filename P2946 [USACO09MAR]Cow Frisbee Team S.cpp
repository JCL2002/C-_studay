#include<bits/stdc++.h>
using namespace std;
const int mod = 1e8;
int n,f;
int dp[2][1002];
int arr[2002];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> f;
    for(int i=1; i<=n; i++) cin >> arr[i];
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<f; j++) dp[i%2][j] = dp[(i-1)%2][j];
        for(int j=0; j<f; j++) dp[i%2][j] = ( dp[(i-1)%2][(f+j-arr[i]%f)%f] + dp[i%2][j] ) % mod;
    }
    cout << dp[n%2][0]-1;
    return 0;
}
