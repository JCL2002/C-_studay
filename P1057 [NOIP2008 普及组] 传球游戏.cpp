#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
int n,m;
int main()
{
    cin >> n >> m;
    dp[0][1]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=dp[i-1][(2*n+j-2)%n+1] + dp[i-1][(2*n+j)%n+1];
    cout << dp[m][1];
    return 0;
}
