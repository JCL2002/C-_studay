#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[5003];
int dp[5005];
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first) return a.second > b.second;
    return a.first > b.first;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr+1,arr+1+n,cmp);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(arr[i].second>arr[j].second) dp[i]=max(dp[i],dp[j]+1);
    int mmax=0;
    for(int i=1;i<=n;i++) mmax=max(mmax,dp[i]);
    cout << mmax+1;
    return 0;
}
