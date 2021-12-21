#include<bits/stdc++.h>
using namespace std;
long long dp[16006];
int arr[16006];
int n,u,v;
vector<int>edge[16006];
void dfs(int i,int fa)
{
    for(int x:edge[i]) if(x!=fa) dfs(x,i),dp[i]+=max(0ll,dp[x]);
    dp[i] += arr[i];
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,1);
    long long ans = - 1ll<<60;
    for(int i=1;i<=n;i++) ans= max(ans,dp[i]);
    cout << ans;
    return 0;
}
