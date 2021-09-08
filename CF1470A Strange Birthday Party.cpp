#include<bits/stdc++.h>
using namespace std;
int n,m;
int k[300005];
int c[300005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        cin >>n>>m;
        for(int i=1;i<=n;i++) cin >> k[i];
        for(int i=1;i<=m;i++) cin >> c[i];
        sort(k+1,k+1+n,cmp);
        long long sum=0;
        int l=1;
        for(int i=1;i<=n;i++)
        {
            if(k[i]>l)
            {
                sum+=c[l++];
            }
            else
            {
                sum+=c[k[i]];
            }
        }
        cout << sum <<endl;
    }
}
