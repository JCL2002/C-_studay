#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[40003];
int w[40003];
int dp[40003];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> w[i] >> c[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    cout << dp[m];
    return 0;
}
