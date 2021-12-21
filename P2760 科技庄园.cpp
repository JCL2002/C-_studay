#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> backpack;
long long dp[105];
int n,m,ti,a;
int arr[10006];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> ti >> a;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin >> arr[i*100+j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            int t;
            cin >> t;
            for(int k=1;k<=t;k++) backpack.push_back({2*i+2*j,arr[i*100+j]});
        }
    int s=min(ti,a-1);
    for(auto x : backpack)
        for(int j=s;j>=x.first;j--)  dp[j] = max(dp[j],dp[j-x.first] + x.second);
    long long ans = 0 ;
    for(int i=1;i<=s;i++) ans = max(ans,dp[i]);
    cout << ans;
    return 0;
}
