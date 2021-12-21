#include<bits/stdc++.h>
using namespace std;
int n,m,W,u,v;
int fa[10004];
void init()
{
    for(int i=1;i<=n;i++) fa[i]=i;
}
int Find(int x)
{
    if(x!=fa[x]) fa[x]=Find(fa[x]);
    return fa[x];
}
void Union(int a,int b)
{
    int ra=Find(a),rb=Find(b);
    fa[ra]=rb;
}
int c[10004];
int w[10004];
int soc[10004];
int sow[10004];
vector<pair<int,int>> iteam;
int dp[10004];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> W;
    init();
    for(int i=1;i<=n;i++) cin >> c[i] >> w[i];
    for(int i=1;i<=m;i++) cin >> u >> v,Union(u,v);
    for(int i=1;i<=n;i++)
    {
        soc[Find(i)]+=c[i];
        sow[Find(i)]+=w[i];
    }
    for(int i =1;i<=n;i++)
    {
        if(soc[i]) iteam.push_back({soc[i],sow[i]});
    }
    for(auto x : iteam)
    {
        for(int j=W;j>=x.first;j--)
        {
            dp[j]=max(dp[j],dp[j-x.first]+x.second);
        }
    }
    cout << dp[W];
    return 0;
}
