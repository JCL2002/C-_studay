//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int arr[2003];
//long long ans[40040006];
//long long dfs(int l,int r)
//{
//    if(ans[l*2000+r]) return ans[l*2000+r];
//    if(l==r)
//    {
//        ans[l*2000+r] = n*arr[l];
//        return ans[l*2000+r];
//    }
//    ans[l*2000+r] = max( (n-r+l)*arr[l]+dfs(l+1,r) , (n-r+l)*arr[r]+dfs(l,r-1) );
//    return ans[l*2000+r];
//}
//int main()
//{
//    cin.sync_with_stdio(false);
//    cin >> n;
//    for(int i=1;i<=n;i++) cin >> arr[i];
//    cout << dfs(1,n);
//    return 0;
//}
//以上做法是记忆化搜索，接下来尝试递推

#include<bits/stdc++.h>
using namespace std;
int n;
int arr[2003];
long long dp[2003][2003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i],dp[i][i]=arr[i]*n;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            dp[j][j+i-1] = max(dp[j+1][j+i-1]+arr[j]*(n-i+1),dp[j][j+i-2]+arr[j+i-1]*(n-i+1));
        }
    }
    cout << dp[1][n];
    return 0;
}
