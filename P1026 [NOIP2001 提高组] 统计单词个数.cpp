#include<bits/stdc++.h>
using namespace std;
string s,cache;
vector<string> dic;
int p,k,n,len;
int dp[203][42];
int num[203][203];//预处理每个区间段的匹配数
signed main()
{
    cin.sync_with_stdio(false);
    cin >> p >> k;
    for(int i=1; i<=p; i++) cin >> cache, s.append(cache);
    len=s.length();
    cin >> n;
    for(int i=1; i<=n; i++) cin >> cache,dic.push_back(cache);
    for(int i=len-1;i>=0;i--)
        for(int j=i;j<len;j++)
        {
            bool t=0;
            for(auto x:dic) if(!(bool)s.substr(i,min((int)x.length(),j-i+1)).find(x)) t=1;
            num[i][j]=num[i+1][j]+t;
        }
    for(int i=1;i<=len;i++)
        for(int j=1;j<=min(k,i);j++)
            for(int z=j-1;z<i;z++) dp[i][j] = max(dp[i][j],dp[z][j-1]+num[z][i-1]);
    cout << dp[len][k] << endl;
    return 0;
}
