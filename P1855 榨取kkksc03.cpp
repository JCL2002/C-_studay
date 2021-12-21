#include<bits/stdc++.h>
using namespace std;
int n,M,T;
int dp[203][203];
int m[203];
int t[203];
int main()
{
    cin >> n >> M >> T;
    for(int i=1;i<=n;i++) cin >> m[i] >> t[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=M;j>=m[i];j--)
        {
            for(int k=T;k>=t[i];k--) dp[j][k]=max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
        }
    }
    cout << dp[M][T];
    return 0;
}
