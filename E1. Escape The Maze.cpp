#include<bits/stdc++.h>
using namespace std;
int t,n,k,u,v;
bool vis[200005];
vector<int>edge[200005];
vector<int>q;
void dfs1(int i,int f)
{
    q.push_back(i);
    if(vis[i])
    {
        vis[ q[q.size() >> 1] ]=1;
        q.pop_back();
        return ;
    }
    for(int x: edge[i]) if(x^f) dfs1(x,i);
    q.pop_back();
}
bool dfs2(int i,int f)
{
    for(int x : edge[i]) if(!vis[x] && x^f && (edge[x].size()==1 || dfs2(x,i) ) ) return 1;
    return 0;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        memset(vis,0,n+2);
        q.clear();
        for(int i=1;i<=n;i++) edge[i].clear();
        for(int i=1;i<=k;i++) cin >> u,vis[u]=1;
        for(int i=1;i<n;i++)
        {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs1(1,1);
        if(dfs2(1,1)) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
    return 0;
}
