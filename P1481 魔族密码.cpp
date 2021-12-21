#include<bits/stdc++.h>
using namespace std;
int dp[2003],n;
string arr[2003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++) if(!arr[i].find(arr[j])) dp[i]=max(dp[i],dp[j]+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout << ans;
    return 0;
}
