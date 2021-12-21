#include<bits/stdc++.h>
using namespace std;
int n,m,dp[2][33];
bool fall[1003];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1,t; i<=n; i++)
    {
        scanf("%d",&t);
        if(t==1) fall[i]=0;
        else fall[i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(fall[i]) for(int j=0;j<=m;j++) dp[1][j]++;
        else for(int j=0;j<=m;j++) dp[0][j]++;
        for(int j=1;j<=m;j++) dp[1][j]=max(dp[1][j],dp[0][j-1]);
        for(int j=1;j<=m;j++) dp[0][j]=max(dp[0][j],dp[1][j-1]);
    }
    int ans=0;
    for(int i=0; i<=m; i++) ans=max ( ans , dp[i%2][i]);
    cout << ans;
    return 0;
}
