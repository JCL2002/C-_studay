#include<bits/stdc++.h>
using namespace std;
#define int long long
long long dp[10006];
int arr[50];
int n,sum;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) arr[i]=i , sum+=arr[i] ;
    if(sum&1)
    {
        cout << 0 ;
        return 0;
    }
    dp[0]=1;sum/=2;
    for(int i=1;i<=n;i++)
        for(int j=sum;j>=arr[i];j--) dp[j] += dp[j-arr[i]];
    cout << (long long) dp[sum]/2;
    return 0;
}
