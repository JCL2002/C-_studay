#include<bits/stdc++.h>
using namespace std;
struct vec
{
    int edge;//±ßÊý
    int weight;//È¨Öµ
};
vec V[200005];
int add[200005];
int n;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(V,0,sizeof(vec)*(n+1));
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            cin >> V[i].weight;
            sum+=V[i].weight;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin >> u >> v ;
            V[u].edge++;
            V[v].edge++;
        }
        int k=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<V[i].edge;j++) add[++k]=V[i].weight;
        }
        sort(add+1,add+n-1,cmp);
        cout << sum << " " ;
        for(int i=1;i<=n-2;i++)
        {
            sum+=add[i];
            cout << sum << " " ;
        }
        cout << endl ;
    }
    return 0;
}
