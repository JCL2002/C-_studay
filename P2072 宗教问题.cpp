#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int num;
int arr[1003];
bool vis[1003];
int dp[1003];
set<int>area;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++)
    {
        area.insert(arr[i]);
        if((int)area.size()>k) num++,area.clear(),area.insert(arr[i]);
    }
    cout << num+1 << endl;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,m+1);
        num=0;
        dp[i]=100000000;
        for(int j=i;j;j--)
        {
            if(!vis[arr[j]]) num++,vis[arr[j]]=1;
            if(num>k) break;
            dp[i]=min(dp[i],dp[j-1]+num);
        }
    }
    cout << dp[n];
    return 0;
}
