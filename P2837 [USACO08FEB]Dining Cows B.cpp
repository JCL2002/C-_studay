#include<bits/stdc++.h>
using namespace std;
//动态规划做法：

//short belong[30005];
//int dp[30005][3];
//int n;
//int main()
//{
//    cin.sync_with_stdio(false);
//    cin >> n;
//    for(int i=1;i<=n;i++) cin >> belong[i];
//    for(int i=1;i<=n;i++)
//    {
//        if(belong[i]==1)
//        {
//            dp[i][1]=dp[i-1][1];
//            dp[i][2]=min(dp[i-1][1],dp[i-1][2]+1);
//        }
//        else
//        {
//            dp[i][1]=dp[i-1][1]+1;
//            dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
//        }
//    }
//    cout << min(dp[n][1],dp[n][2]);
//    return 0;
//}


//枚举断点做法：
int sum[30005];
int n;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp==2) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,sum[i]+(n-i)-(sum[n]-sum[i-1]));
    }
    cout <<ans;
    return 0;
}
