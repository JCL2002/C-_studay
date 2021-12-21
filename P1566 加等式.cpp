#include<bits/stdc++.h>
using namespace std;
int t,n;
int arr[33];
int dp[1003];

int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n ;
        memset(dp,0,sizeof(int)*(1001));
        dp[0]=1;
        for(int i=1;i<=n;i++) cin >> arr[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1000;j>=arr[i];j--)
            {
                dp[j] += dp[j-arr[i]];
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++) sum+= dp[ arr[i] ];
        cout << sum-n << endl;
    }
    return 0;
}
