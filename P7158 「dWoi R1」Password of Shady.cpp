#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k;
const int mod = 998244353;
int dp[100005][2];
signed main()
{
    cin >> t;
    dp[1][0]=1;
    dp[1][1]=8;
    for(int i=2; i<=100000; i++)
    {
        dp[i][1] = (9*dp[i-1][1] + dp[i-1][0]) %mod;
        dp[i][0] = (9*dp[i-1][0] + dp[i-1][1]) %mod;
    }
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        if(n==1) cout << 9 << endl;
        else printf("%lld \n",dp[n][1]);
    }
    return 0;
}
