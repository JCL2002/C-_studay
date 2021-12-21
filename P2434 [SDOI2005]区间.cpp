#include<bits/stdc++.h>
using namespace std;
int cf[2000006];
int fa[2000006];
int n,u,v;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> u >> v;
        cf[2*u-1]++;cf[2*v]--;
    }
    int sum=0;
    for(int i=1;i<=2000000;i++)
    {
        sum+=cf[i];
        cf[i]=sum;
    }
    for(int i=2000000;i;i--)
    {
        if(cf[i])
        {
            if(cf[i+1]) fa[i]=fa[i+1];
            else fa[i]=i;
        }
    }
    int i=1;
    while(i<=2000000)
    {
        if(fa[i])
        {
            cout << (i+1)/2 << " " << (fa[i]+1)/2 << "\n";
            i=fa[i]+1;
            continue;
        }
        i++;
    }
    return 0;
}
