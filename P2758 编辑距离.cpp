#include<bits/stdc++.h>
using namespace std;
char s[2003],a[2003];
int dp[2003][2003];
int n,m;
int main()
{
    cin.sync_with_stdio(false);
    cin >> s+1 >> a+1;
    n=strlen(s+1);m=strlen(a+1);
    for(int i=0;i<=n;i++) dp[i][0]= i;
    for(int i=0;i<=m;i++) dp[0][i]= i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i] == a[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min( dp[i-1][j]+1 , min( dp[i][j-1] +1 , dp[i-1][j-1] +1 ) );
        }
    }
    cout << dp[n][m];
    return 0;
}
