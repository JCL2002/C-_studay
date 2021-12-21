#include<bits/stdc++.h>
using namespace std;
int t,n;
int dp[5][32770];
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    dp[0][0]=1;
    for(int i=1; i<=181; i++)
    {
        for(int j=i*i;j<=32768;j++)
        {
            for(int k=1;k<=4;k++)
            {
                dp[k][j] += dp[k-1][j-i*i];
            }
        }
    }
    while(t--)
    {
        cin >> n;
        cout << dp[1][n] + dp[2][n] +dp[3][n] + dp[4][n] << endl;
    }
    return 0;
}
