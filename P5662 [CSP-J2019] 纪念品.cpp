#include<bits/stdc++.h>
using namespace std;
int dp[10004];
int iteam[102][102];
int t,n,m;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t >> n >> m;
    for(int i=1;i<=t;i++)
        for(int j=1;j<=n;j++) cin >> iteam[i][j];
    for(int i=1;i<t;i++)
    {
        for(int i=1;i<=m;i++) dp[i]=i;
        for(int j=1;j<=n;j++)
            for(int k=iteam[i][j];k<=m;k++) dp[k] = max(dp[k], dp[k-iteam[i][j] ] + iteam[i+1][j] );
        for(int i=1;i<=m;i++) m=max(m,dp[i]);
    }
    cout << m ;
}
