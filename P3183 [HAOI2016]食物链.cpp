#include<bits/stdc++.h>
using namespace std;
int ans[100005];
int indeg[100005];
vector<int>edge[100005];
bool ori[100004];
long long sum;
int n,m,s,t;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> s >> t;
        edge[s].push_back(t);
        indeg[t]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(!indeg[i]) q.push(i),ans[i]=ori[i]=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(int x : edge[s])
        {
            indeg[x]--;
            ans[x]+=ans[s];
            if(!indeg[x]) q.push(x);
        }
        if(edge[s].empty() && !ori[s]) sum+=ans[s];
    }
    cout << sum;
    return 0;
}
