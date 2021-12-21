#include<bits/stdc++.h>
using namespace std;
pair<int,int> l[20004];
int n;
int dp[20004][2];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> l[i].first >> l[i].second;
    l[0]={1,1};
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = min( abs(l[i].second - l[i-1].second) + dp[i-1][1] , abs( l[i].second - l[i-1].first ) + dp[i-1][0] ) + l[i].second - l[i].first +1 ;
        dp[i][1] = min( abs(l[i].first - l[i-1].second) + dp[i-1][1] , abs( l[i].first - l[i-1].first ) + dp[i-1][0] ) + l[i].second - l[i].first +1 ;
    }
    cout << min(dp[n][0]+ n-l[n].first , dp[n][1] +n-l[n].second)-1;
    return 0;
}
