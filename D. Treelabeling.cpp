#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<int>edge[200005];
bool vis[200005];
int ans[200005];
vector<int>Left,Right;//二部图
void bfs(int i,int depth)//奇数在左边，偶数在右边
{
    vis[i]=1;
    if(depth&1) Left.push_back(i);
    else Right.push_back(i);
    for(int j=0; j<(int)edge[i].size(); j++)
    {
        if(!vis[ edge[i][j] ])
        {
            bfs(edge[i][j],depth+1);
        }
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1; i<=n; i++) edge[i].clear();
        Left.clear();
        Right.clear();
        memset(vis,0,n+2);
        for(int i=1; i<n; i++)
        {
            int u,v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        bfs(1,1);
        memset(vis,0,n+2);
        int s=Left.size();
        int S=Right.size();
        int base=1;
        if(s<S)
        {
            while(s)
            {
                if(s&1)
                {
                    for(int i= (1 << (base-1)); i<= (1 << base) -1; i++)
                    {
                        ans[Left.back()]=i;
                        Left.pop_back();
                        vis[i]=1;
                    }
                }
                base ++;
                s >>= 1;
            }
            for(int i=1; i<=n; i++)
            {
                if(!vis[i])
                {
                    ans[Right.back()]=i;
                    Right.pop_back();
                }
            }
        }
        else
        {
            while(S)
            {
                if(S&1)
                {
                    for(int i= (1 << (base-1)); i<= (1 << base) -1; i++)
                    {
                        ans[Right.back()]=i;
                        Right.pop_back();
                        vis[i]=1;
                    }
                }
                base ++;
                S >>= 1;
            }
            for(int i=1; i<=n; i++)
            {
                if(!vis[i])
                {
                    ans[Left.back()]=i;
                    Left.pop_back();
                }
            }
        }
        for(int i=1; i<=n; i++) cout << ans[i] << " " ;
        cout << endl;
    }
    return 0;
}
/*
1
6
2 3
4 6
2 6
1 6
5 6
*/
