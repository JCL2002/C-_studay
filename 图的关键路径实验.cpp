#include<bits/stdc++.h>
using namespace std;
int n,m,num[50],u,v,w,indeg[50],outdeg[50],dis[50];
vector<pair<int,int>> edge[50];
bool vis[50];
bool spfa() // spfaËã·¨
{
    queue<int> q;
    m=0;
    for(int i=0; i<n; i++)
    {
        if(!indeg[i]) q.push(i);
        if(!outdeg[i]) m++;
    }
    if( q.empty() || q.size()>1 || m > 1 || m == 0) return 1;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        vis[s]=0;
        num[s] ++;
        if(num[s] > n) return 1;
        for(auto x : edge[s])
        {
            if(dis[x.first] < dis[s] + x.second)
            {
                dis[x.first] = dis[s] + x.second;
                if(!vis[x.first]) vis[x.first] = 1, q.push(x.first);
            }
        }
    }
    return 0;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >>  u >> v >> w, edge[u].push_back( { v, w } ), indeg[v]++, outdeg[u]++ ;
    if(spfa()) cout << "false" ;
    else
    {
        int mmax=0;
        for(int i=1; i<=n; i++) mmax=max(mmax,dis[i]);
        cout << mmax;
    }
    return 0;
}
