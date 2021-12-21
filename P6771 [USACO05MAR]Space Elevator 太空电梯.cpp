#include<bits/stdc++.h>
using namespace std;
int n,h,a,c;
vector<pair<int,int>> iteam;
bool dp[40004]={1,};
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> h >> a >> c;
        for(int j=1;j<=c;j++) iteam.push_back({a,h});
    }
    sort(iteam.begin(),iteam.end());
    for(auto x : iteam)
        for(int j=x.first;j>=x.second;j--) dp[j] += dp[j-x.second];
    int ans=0;
    for(int j=40000;j;j--)if(dp[j]){ans=j;break;}
    cout << ans;
    return 0;
}
