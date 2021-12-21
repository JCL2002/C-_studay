#include<bits/stdc++.h>
using namespace std;
int n,cnt[5000006],t,mmax,dp[5000006];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> t,cnt[t]++,mmax=max(mmax,t);
    for(int i=1;i<=mmax;i++) if(cnt[i]) dp[i]=i*cnt[i];
    for(int i=1;i<=mmax;i++) cout << dp[i] << " ";
    for(int i=mmax;i;i--)
        for(int j=i*2;j<=mmax;j+=i) if(dp[j] && dp[i]+dp[j]-i*(cnt[j]) > dp[i]) dp[i]=dp[i]+dp[j]-i*(cnt[j]),cnt[i]+=cnt[j];
    cout << dp[1]+n-cnt[1];
    return 0;
}
