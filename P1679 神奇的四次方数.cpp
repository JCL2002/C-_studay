#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int w[18];
int m;
int main()
{
    cin >> m;
    for(int i=1;i<=17;i++)
    {
        w[i]=i*i*i*i;
    }
    for(int i=1;i<=100000;i++) dp[i]=0x3f3f3f3f;
    for(int i=1;i<=17;i++)
    {
        for(int j=w[i];j<=100000;j++) dp[j]=min(dp[j],dp[j-w[i]]+1);
    }
    cout << dp[m];
    return 0;
}
