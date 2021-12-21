#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> obj[1003];
int dp[10003][1003];
int last;
int main()
{
    cin.sync_with_stdio(false);
    cin >> m >> n;
    int c,w,g;
    for(int i=1;i<=n;i++)
    {
        cin >> w >> c >> g;
        obj[g].push_back({c,w});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(int)obj[i].size();j++)
        {
            for(int k=obj[i][j].second;k<=m;k++)
            {
                dp[last+1][k]=max(dp[last+1][k],max(dp[last][k],dp[last][k-obj[i][j].second]+obj[i][j].first));
            }
        }
        for(int j=1;j<=m;j++) dp[last+1][j]=max(dp[last+1][j],dp[last][j]);
        if(obj[i].size()) last++;

    }
    cout << dp[last][m] ;
    return 0;
}
//ºÕ¶ûÐÁ¸ùÄ¬Ë¹¿ÏÏãÔí
