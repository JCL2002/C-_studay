#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2003];
vector<vector<int> > sp;
vector<pair<int,int> > zo;
vector< pair<int,int> > wq;
vector<int> val;
int n,m,x;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        if(x==1)
        {
            int a,b;
            cin >> a >>b;
            val.clear();
            val.push_back(0);
            for(int i=1;i<=m;i++) val.push_back(a*i*i-b*i);
            sp.push_back(val);
        }
        if(x==2)
        {
            int a,b,c;
            cin >> a >> b >> c;
            c=min(c,m/b);
            for(int i=1;i<=c;i++) zo.push_back({b,a});
        }
        if(x==3)
        {
            int a,b;
            cin >> a >> b;
            wq.push_back({b,a});
        }
    }
    for(auto x : zo)
        for(int j=m;j>=x.first;j--) dp[j] = max( dp[j] , dp[j-x.first] + x.second );
    for(auto x : wq)
        for(int j=x.first;j<=m;j++) dp[j] = max( dp[j] , dp[j-x.first] + x.second );
    for(auto x: sp)
    {
        for(int i=m;i;i--)
        {
            for(int j=1;j<=i;j++) dp[i]=max(dp[i],dp[i-j]+x[j]);
        }
    }
    cout << dp[m];
    return 0;
}
