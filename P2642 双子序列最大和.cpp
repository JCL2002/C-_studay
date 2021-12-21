#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
int mm=-9999999999999999;
int dp[1000006][2];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    cin >> dp[1][0] ;
    dp[0][1]=-9999999999999999;dp[1][1]=-9999999999999999;dp[0][0]=-9999999999999999;
    for(int i=2;i<=n;i++)
    {
        cin >> t;
        dp[i][0] = max(dp[i-1][0]+t,t);
        mm=max(mm,dp[i-2][0]);
        dp[i][1] = max(mm+t,dp[i-1][1]+t);

    }
    int mmax=-9999999999999999;
    for(int i=1;i<=n;i++) mmax=max(mmax,dp[i][1]);
    cout << mmax << endl;
    return 0;
}
