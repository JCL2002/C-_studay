#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int fa[10004];
bool vis[10004];
int depth[10004];
void init()
{
    for(int i=1; i<=n; i++) fa[i]=i;
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
struct road
{
    int s,t;
    int w;
};
bool cmp(road a,road b)
{
    return a.w>b.w;
}
road arr[50004];
struct node
{
    int t;
    int w;
};
vector<node> edge[10004];
int root[10004][20];
int mmin[10004][20];
void built(int i,int r,int w,int dep)
{
    root[i][0]=r;
    mmin[i][0]=w;
    vis[i]=1;
    depth[i]=dep;
    for(int j=0; j<(int)edge[i].size(); j++)
    {
        if(!vis[ edge[i][j].t ]) built(edge[i][j].t,i,edge[i][j].w,dep+1);
    }
}
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    init();
    for(int i=1; i<=m; i++) cin >> arr[i].s >> arr[i].t >> arr[i].w;
    sort(arr+1,arr+1+m,cmp);
    for(int i=1; i<=m; i++)
    {
        if(Find(arr[i].s)!=Find(arr[i].t))
        {
            edge[ arr[i].s ].push_back(node{ arr[i].t, arr[i].w });
            edge[ arr[i].t ].push_back(node{ arr[i].s, arr[i].w });
            Union(arr[i].s,arr[i].t);
        }
    }
    for(int i=1; i<=n; i++) if(!vis[i]) built(i,i,10000000000000,1);
    for(int i=1; i<20; i++)
    {
        for(int j=1; j<=n; j++) root[j][i] = root[ root[j][i-1] ][i-1];
    }
    for(int i=1; i<20; i++)
    {
        for(int j=1; j<=n; j++) mmin[j][i] = min(mmin[j][i-1],mmin[ root[j][i-1] ][i-1]);
    }
    int q;
    cin >> q;
    int x,y;
    for(int i=1; i<=q; i++)
    {
        cin >> x >> y;
        if(Find(x)==Find(y))
        {
            int ans=100000000000000;
            if(depth[x]<depth[y]) swap(x,y);
            for(int i=19; i>=0; i--)
            {
                if(depth[root[x][i]]>=depth[y])
                {
                    ans=min(ans,mmin[x][i]);
                    x=root[x][i];
                }
            }
            if(x==y)
            {
                cout << ans << endl;
                continue;
            }
            for(int i=19; i>=0; i--)
            {
                if(root[x][i]!=root[y][i])
                {
                    ans=min( ans, min(mmin[x][i],mmin[y][i]) );
                    x=root[x][i];
                    y=root[y][i];
                }
            }
            ans=min( ans, min(mmin[x][0],mmin[y][0]) );
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
