#include<bits/stdc++.h>
using namespace std;
int v,n,C;
int dp[100005];
int w[100005];
int c[100005];
int main()
{
    cin >>v >> n >> C;
    for(int i=1;i<=n;i++) cin >> c[i] >> w[i];
    for(int i=1;i<=n;i++)
        for(int j=C;j>=w[i];j--) dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    if(dp[C]<v) cout << "Impossible";
    else
    {
        int i=C;
        for(;i>=0;i--) if(dp[i]<v) break;
        cout << C-i-1;
    }
    return 0;
}
