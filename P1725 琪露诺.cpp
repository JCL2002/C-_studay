#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r;
deque<pair<int,int> >d;
int dp[400005];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> l >> r;
    for(int i=0;i<=n;i++) cin >> dp[i];
    for(int i=1;i<l;i++) dp[i]=-999999999999ll;
    for(int i=l;i<=n+r;i++)
    {
        while(!d.empty()&&dp[i-l]>=d.back().first) d.pop_back();
        d.push_back({dp[i-l],i-l});
        while(d.front().second<i-r) d.pop_front();
        dp[i] += d.front().first;
    }
    int ans = -999999999999ll;
    for(int i=n+1;i<=r+n;i++) if(dp[i]) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
