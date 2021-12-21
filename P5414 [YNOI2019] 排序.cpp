#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,sum,mmax;
int arr[102];
int dp[102];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(dp,0,sizeof(int)*(n+1));
        sum=0;mmax=-100000000;
        for(int i=1;i<=n;i++) cin >> arr[i],sum+=arr[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
                if(arr[i]>=arr[j]) dp[i]=max(dp[i],dp[j]);
            dp[i]+=arr[i];
        }
        for(int i=1;i<=n;i++) mmax=max(mmax,dp[i]);
        cout << sum-mmax << endl;
    }
    return 0;
}
