#include<bits/stdc++.h>
using namespace std;
int x,y;
int num[102][102];
int dp[2][102];
int main()
{
    cin.sync_with_stdio(false);
    cin >> x >> y;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++) cin >> num[i][j];
    dp[1][1]=num[1][1];
    for(int i=2;i<=y;i++)
    {
        memset(dp[i%2],0,sizeof(int)*(x+1));
        for(int j=1;j<=x;j++)
        {
            if(dp[(i-1)%2][j-1]) dp[i%2][j] = max( dp[i%2][j],dp[(i-1)%2][j-1] + num[j][i] );
            if(dp[(i-1)%2][j]) dp[i%2][j] = max( dp[i%2][j],dp[(i-1)%2][j] + num[j][i] );
            if(dp[(i-1)%2][j+1]) dp[i%2][j] = max( dp[i%2][j],dp[(i-1)%2][j+1] + num[j][i] );
        }
    }
    cout << dp[y%2][x];
    return 0;
}
