#include<bits/stdc++.h>
using namespace std;
vector<int>edge[105];
int n,u,v;
long long sum,ans=9999999999999ll;
int num[105];
bool vis[102];
void dfs(int i,int depth)
{
    vis[i]=1;
    sum += depth*num[i];
    for(auto x : edge[i]) if(!vis[x]) dfs(x,depth+1);
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> num[i] >> u >> v;
        if(u) edge[i].push_back(u);
        if(v) edge[i].push_back(v);
        if(u) edge[u].push_back(i);
        if(v) edge[v].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,n+1);
        sum = 0ll;
        dfs(i,0);
        ans = min( ans , sum );
    }
    cout << ans;
    return 0;
}
