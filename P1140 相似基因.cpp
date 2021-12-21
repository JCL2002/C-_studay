#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[103],b[103];
string s;
int dp[203][203];
int val[5][5]={
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >>s;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='A') a[i]=0;
        if(s[i-1]=='C') a[i]=1;
        if(s[i-1]=='G') a[i]=2;
        if(s[i-1]=='T') a[i]=3;
    }
    cin >> m >>s;
    for(int i=1;i<=m;i++)
    {
        if(s[i-1]=='A') b[i]=0;
        if(s[i-1]=='C') b[i]=1;
        if(s[i-1]=='G') b[i]=2;
        if(s[i-1]=='T') b[i]=3;
    }
    for(int i=1;i<=n;i++) dp[i][0]= dp[i-1][0] + val[ a[i] ][4];
    for(int i=1;i<=m;i++) dp[0][i] = dp[0][i-1] + val[4][ b[i] ];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j] = max(dp[i-1][j-1]+val[ a[i] ][ b[j] ], max( dp[i-1][j] + val[ a[i] ][4] , dp[i][j-1] + val[ 4 ][ b[j] ] ) );
    cout << dp[n][m];
    return 0;
}
