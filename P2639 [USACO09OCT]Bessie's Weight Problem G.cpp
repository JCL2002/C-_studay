#include<bits/stdc++.h>
using namespace std;
int n,s;
int dp[45005];
int w[505];
int main()
{
    cin.sync_with_stdio(false);
    cin >> s >> n;
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=s;j>=w[i];j--) dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
    }
    cout << dp[s];
    return 0;
}
