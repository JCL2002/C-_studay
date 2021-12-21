#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
int dp[1003];
int n,p,s,w,c;
int ans;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> p >> s;
    for(int i=1;i<=n;i++) cin >> w >> c , q.push({w,c});
    bool flag;
    while(!q.empty())
    {
        auto x = q.top() ; q.pop();
        flag=0;
        ans=x.first;
        for(int i=s;i>=ans;i--) dp[i] = max(dp[i] , dp[i-ans] + x.second);
        for(int i=1;i<=s;i++) if(dp[i]>=p) {flag=1;break;}
        if(flag) break;
    }
    if(flag) cout << ans ;
    else cout << "No Solution!" ;
    return 0;
}
