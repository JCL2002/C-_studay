#include<bits/stdc++.h>
using namespace std;
int n,k,from,to,cost;
int sum=1,Last=1;
vector<pair<int,int>> edge[10004];
struct node
{
    int s;
    int len;
};
bool vis[10004];
int dis[10004];
void spfa()
{
    queue<int>q;
    q.push(1);
    dis[1]=0;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        vis[s]=0;
        for(auto x : edge[s])
        {
//            cout << s << " -> " << x.first << " : " << x.second << endl;
            if(dis[x.first] > dis[s]+ x.second)
            {
                dis[x.first] = dis[s]+ x.second;
                if(!vis[x.first]) q.push(x.first),vis[x.first]=1;
            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n+2;i++) dis[i]=0x3f3f3f3f;
    for(int i=1; i<=n; i++)
    {
        cin >> k;
        for(int j=1; j<=k; j++)
        {
            while(cin >> from && from)
            {
                cin >> cost;
                edge[from-1+sum-Last+1].push_back({j+sum,cost});
            }
        }
        Last=k;
        sum+=k;
    }
    spfa();
    int mmin=0x3f3f3f3f;
    for(int i=sum+1;i>sum-k;i--) mmin=min(mmin,dis[i]);
    cout << mmin;
    return 0;
}
