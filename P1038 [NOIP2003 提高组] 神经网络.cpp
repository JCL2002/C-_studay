#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int u[105];
int indeg[105];
int sum[105];
vector<pair<int,int>>edge[105];
queue<int> active;
vector<pair<int,int>>ans;
bool vis[105];
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.first < b.first;
}
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> sum[i] >> u[i];
        if(sum[i]) sum[i]+=u[i];
    }
    for(int i=1;i<=m;i++)
    {
        int s,t,w;
        cin >> s >> t >> w;
        edge[s].push_back({t,w});
        indeg[t]++;
    }
    for(int i=1;i<=n;i++) if(!indeg[i]) active.push(i);
    while(!active.empty())
    {
        int s=active.front();
        active.pop();
        vis[s]=1;
        if(sum[s]>u[s])
        {
            if(edge[s].size()==0u) ans.push_back({s,sum[s]-u[s]});
            else
            {
                for(int i=0;i<(int)edge[s].size();i++)
                {
                    sum[ edge[s][i].first ]+=(sum[s]-u[s])*edge[s][i].second;
                    indeg[ edge[s][i].first ] --;
                    if(!indeg[ edge[s][i].first ]) active.push(edge[s][i].first);
                }
            }
        }
        if(active.empty())
        {
            for(int i=1;i<=n;i++)
            {
                if(!vis[i]&&sum[i]>u[i]) active.push(i);
            }
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    if(ans.size())
    {
        for(auto x: ans) cout << x.first << " " << x.second << endl;
    }
    else
    {
        cout << "NULL" ;
    }
    return 0;
}
