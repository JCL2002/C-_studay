#include<bits/stdc++.h>
using namespace std;
int s,n,d;
int dp[40000000];
vector<pair<int,int> > iteam;
int main()
{
    cin.sync_with_stdio(false);
    cin >> s >> n >> d;
    int c,v;
    for(int i=1;i<=d;i++)
    {
        cin >> c >> v;
        iteam.push_back({c,v});
    }
    for(auto x : iteam)
        for(int j=x.first;j<=(int)n*s;j++) dp[j] = max(dp[j],dp[j-x.first]+x.second);
    for(int i=1;i<=n;i++) s+=dp[s];
    cout << s;
    return 0;
}
