#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1003];
int arr[1003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>0;j--)
        {
            dp[j]=max(dp[j],dp[j-1]+(arr[i]==j));
        }
    }
    int mmax=0;
    for(int i=1;i<=n;i++) mmax=max(mmax,dp[i]);
    cout << mmax;
    return 0;
}
