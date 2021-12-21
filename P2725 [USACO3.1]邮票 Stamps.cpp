#include<bits/stdc++.h>
using namespace std;
long long dp[2000006];
long long k,n;
long long val[50];
int main()
{
    cin >> k >>n ;
    for(int i=1;i<=2000005;i++) dp[i]=99999999999ll;
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=1;i<=n;i++)
        for(int j=val[i];j<2000006;j++) dp[j] =min (dp[j] , dp[j-val[i]]+1);
    int mmin=0;
    for(int i=1;i<=2000005;i++)
    {
        if(dp[i]<=k) mmin++;
        else break;
    }
    cout << mmin;
    return 0;
}
