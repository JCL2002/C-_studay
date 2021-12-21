#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int n,p;
int dp[2003];
vector<int> is[2003];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> p;
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(i%j==0) is[i].push_back(j);
    for(int i=2;i<=p;i++)
        for(int j=n;j>0;j--)
            for(int x : is[j]) dp[j] =(dp[j]+dp[x])%mod;
    int sum=0;
    for(int i=1;i<=n;i++) sum =(sum + dp[i]) % mod;
    cout << sum;
    return 0;
}
