#include<bits/stdc++.h>
using namespace std;
int dp[203];
int lg(long long x)
{
    int n=0;int c=x;
    while(x>1) n++,x>>=1;
    if((1ll<<n)<c) n++;
    return n;
    return n;
}
long long hight[203];
int n;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> hight[i] ;
    for(int i=2;i<=n;i++) dp[i]=500000;
    for(int i=2;i<=n;i++)
    {
        if( hight[i]-hight[i-1] <=1 ) dp[i] = min(dp[i],dp[i-1]+1);
        for(int j=1;j<i;j++)
        {
            for(int k=lg(hight[i]-hight[j])+j;k<i;k++)
            {
                dp[i]=min(dp[i],dp[k]+k-j+1);
            }
        }
    }
    if(dp[n]==500000) cout << -1;
    else cout << dp[n];
    return 0;
}
