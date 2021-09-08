#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int i;
    int val;
};
node arr[200005];
int n;
long long sum[200005];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
bool pmc(node a,node b)
{
    return a.i<b.i;
}
signed main()
{
    int t;
    cin >>t;
    while(t--)
    {
        cin >>n;
        for(int i=1;i<=n;i++)
        {
            int val;
            cin >> val;
            arr[i].i=i;
            arr[i].val=val;
        }
        arr[n+1].val=-1;
        sort(arr+1,arr+1+n,cmp);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i].val;
        int mmax=n;
        while(mmax>1&&sum[mmax-1]>=arr[mmax].val) mmax--;
        sort(arr+mmax,arr+1+n,pmc);
        cout <<n-mmax+1<<endl;
        for(int i=mmax;i<=n;i++) cout <<arr[i].i<<" ";
        cout <<endl;
    }
    return 0;
}
