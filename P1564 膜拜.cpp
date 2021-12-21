#include<bits/stdc++.h>
using namespace std;
int dp[2505];
int sum[2505];
int n,t,m;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> t;
        if(t==1) sum[i]=sum[i-1]-1;
        else sum[i]=sum[i-1]+1;
        dp[i]=0x3f3f3f3f;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++) if(abs(sum[i]-sum[j-1])<=m || abs(sum[i]-sum[j-1]) == abs(i-j)+1 ) dp[i]=min(dp[i],dp[j-1]+1);
    cout << dp[n];
    return 0;
}
