#include<bits/stdc++.h>
using namespace std;
int n,arr[6003],u,v;
int dp[6003][2];
bool boss[6003];
vector<int> edge[6003];
void dfs(int i)
{
    for(auto x : edge[i])
    {
        dfs(x);
        dp[i][0] += max(dp[x][0],dp[x][1]);
        dp[i][1] += dp[x][0];
    }
    dp[i][1] += arr[i];
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        edge[v].push_back(u);
        boss[u]=1;
    }
    int bos;
    for(int i=1;i<=n;i++) if(!boss[i]){bos=i;break;}
    dfs(bos);
    cout << max(dp[bos][0],dp[bos][1]);
    return 0;
}
