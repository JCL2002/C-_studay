#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[103];
long long dp[103][103];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> arr[i];
    sort(arr+1,arr+1+m);arr[m+1]=n+1;
    for(int len=1;len<=m;len++)
    {
        for(int s=1;s<=m-len+1;s++)
        {
            int t=s+len-1;
            dp[s][t]=999999999999ll;
            for(int k=s;k<=t;k++)
            {
                dp[s][t] = min(dp[s][t],dp[s][k-1]+dp[k+1][t]+arr[t+1]-arr[s-1]-2);
            }
        }
    }
    cout << dp[1][m];
    return 0;
}
