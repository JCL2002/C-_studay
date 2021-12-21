#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int arr[10004];
int ans[10004];
int dp[10004];
signed main()
{
    scanf("%lld",&n);
    for(int i=1; i<=n; i++) scanf("%lld",arr+i),dp[i]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(arr[i]>=arr[j] && dp[i] < dp[j]+1)
            {
                dp[i]= dp[j]+1;
                ans[i]=ans[j];
            }
        }
        ans[i]+=arr[i];
    }
    for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
    return 0;
}
