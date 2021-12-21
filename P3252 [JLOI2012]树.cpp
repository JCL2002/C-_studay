#include<bits/stdc++.h>
using namespace std;
int n,s,u,v;
int arr[100005];
vector<int>edge[100005];
int ans;
void dfs(int i,int dep)
{
    if( dep > s ) return ;
    if(dep == s )
    {
        ans++;
        return;
    }
    for(int x:edge[i]) dfs(x,dep+arr[x]);
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> s;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<n; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for(int i=1;i<=n;i++) dfs(i,arr[i]);
    cout << ans;
    return 0;
}
