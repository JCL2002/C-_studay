#include<bits/stdc++.h>
using namespace std;
int n,m;
int ye[505][505];
int blo[505][505];
int dp[505][505][3];
int main()
{
    cin.sync_with_stdio(false);
    while(1)
    {
        cin >> n >> m;
        if(n+m==0) break;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) cin >> ye[i][j];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) cin >> blo[i][j];
        for(int i=1 ; i<=n; i++)
            for(int j=1; j<=m; j++) dp[i][j][0] = dp[i][j][1] =dp[i][j][2]=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                dp[i][j][1] = dp[i][j-1][1] + dp[i-1][j][0] - dp[i-1][j-1][0] +ye[i][j];
                dp[i][j][2] = dp[i-1][j][2] + dp[i][j-1][0] - dp[i-1][j-1][0] + blo[i][j];
                dp[i][j][0] = max( dp[i][j][1] , dp[i][j][2] );
            }
        cout << dp[n][m][0] << endl;
    }
    return 0;
}
