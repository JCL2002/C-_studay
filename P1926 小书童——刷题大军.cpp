#include<bits/stdc++.h>
using namespace std;
int cost[55];
int num[155];
int n,m,k,r;
int W[20];
int w[20];
int c[20];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> k >> r;
    k++;
    for(int i=1;i<=n;i++) cin >> W[i];
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=m;i++) cin >> c[i];
    for(int i=1;i<=k;i++) cost[i]=0x3f3f3f3f;
    for(int i=1;i<=m;i++)
    {
        for(int j=k;j>=c[i];j--) cost[j]=min(cost[j],cost[j-c[i]]+w[i]);
        for(int j=c[i]-1;j>0;j--) cost[j]=min(cost[j],w[i]);
    }
    r-=cost[k];
    for(int i=1;i<=n;i++)
    {
        for(int j=r;j>=W[i];j--) num[j]=max(num[j],num[j-W[i]]+1);
    }
    cout << num[r];
    return 0;
}
