#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[10004];
struct work
{
    int s,e;
};
work arr[10004];
vector<int> to[10004];
bool cmp(work a,work b)
{
    return a.s < b.s;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1,len;i<=k;i++) cin >> arr[i].s >> len , arr[i].e=len+arr[i].s-1;
    sort(arr+1,arr+1+k,cmp);
    for(int i=1;i<=k;i++) to[ arr[i].s ].push_back(arr[i].e);
    for(int i=n;i>0;i--)
    {
        if(to[i].empty()) dp[i]=dp[i+1]+1;
        else for(int x : to[i]) dp[i]=max(dp[i],dp[x+1]);
    }
    cout << dp[1];
    return 0;
}
