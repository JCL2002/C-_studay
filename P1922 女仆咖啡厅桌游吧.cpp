#include<bits/stdc++.h>
using namespace std;
int n,s,t;
vector<int> to[100005];
bool vis[100005];
int built[100005];
int dfs(int i)
{
    vis[i]=1;
    int sum=0;
    int epty=0;
    for(int x : to[i])
    {
        if(vis[x]) continue;
        int tmp=dfs(x);
        if(tmp>1) sum+=tmp;
        else epty++;
    }
    if(epty) sum+= 2*((epty+1)/2);
    return max(1,sum);
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<n; i++) cin >> s >> t,to[s].push_back(t),to[t].push_back(s);
    cout << dfs(1)/2;
    return 0;
}
