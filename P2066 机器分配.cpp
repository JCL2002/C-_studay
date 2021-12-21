#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[20][20];
int dp[20];
int turn[20][20];
vector<int> ans;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> arr[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>0;j--)
        {
            for(int k=j;k>=0;k--)
            {
                if(dp[j] < dp[j-k] + arr[i][k])
                {
                    dp[j] = dp[j-k] + arr[i][k] ;
                    turn[i][j] = k;
                }
            }
        }
    }
    cout << dp[m] << endl;;
    for (int i=n,j=m;i;--i)
	{
		ans.push_back(turn[i][j]);
		j-=turn[i][j];	//算出最优方案第i+1~n公司共使用了几台机器，也就是f(i,j)是由f(i+1,?)转移过来的
	}
	for(int i=1;i<=(int)ans.size();i++)
    {
        cout << i << " " << ans[n-i] << endl;
    }
    return 0;
}
