#include<bits/stdc++.h>
using namespace std;
#define int long long
int v,n;
int num[26],dp[10004]= {1,};
signed main()
{
    cin.sync_with_stdio(false);
    cin >> v >> n;
    for(int i=1; i<=v; i++) cin >> num[i];
    for(int i=1; i<=v; i++)
        for(int j=num[i] ; j<=n ;j++) dp[j] += dp[j-num[i]];
    cout << dp[n];
    return 0;
}
