#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int w1[102];
int w2[102];
int c[102];
int dp[1003][1003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i=1;i<=n;i++) cin >> c[i] >> w1[i] >> w2[i] ;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=w1[i];j--)
        {
            for(int k=x;k>=w2[i];k--) dp[j][k]=max(dp[j][k],dp[j-w1[i]][k-w2[i]]+c[i]);
        }
    }
    cout << dp[m][x];
    return 0;
}
