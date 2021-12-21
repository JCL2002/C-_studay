#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
int dp[1505][2];
vector<int> edge[1505];
void dfs(int i,int fa)
{
//    cout << "debug " << i << endl;
    for(auto x : edge[i])
    {
        if(x==fa) continue;
        dfs(x,i);
        dp[i][0] += min(dp[x][1],dp[x][0]+1);
        dp[i][1] += min(dp[x][0],dp[x][1]);
    }
    dp[i][1]++;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s >> m;
        for(int j=1;j<=m;j++)
        {
            cin >> t;
            edge[s].push_back(t);
            edge[t].push_back(s);
        }
    }
    dfs(0,0);
    cout << min(dp[0][0],dp[0][1]);
    return 0;
}
