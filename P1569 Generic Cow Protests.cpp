#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1003];
int arr[1003];
int sum;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++)
    {
        sum=0;
        dp[i]=-1;
        for(int j=i; j>0; j--)
        {
            sum+=arr[j];
            if(sum>=0) dp[i]=max(dp[i],(dp[j-1]!=-1)*(dp[j-1]+2)-1);
        }
    }
    if(dp[n]>=0) cout << dp[n];
    else cout << "Impossible";
    return 0;
}
