#include<bits/stdc++.h>
using namespace std;
#define int long long
long long dp[1003][1003];
int n;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> dp[i][i];
    for(int i=2;i<=n;i++)//���䳤��
    {
        for(int s=1;s<=n-i+1;s++)//�������
        {
            //���䷶Χ��[s,s+i-1]
            for(int b=s;b<s+i-1;b++)
            {
                //������:[s,b],������:[b+1,s+i-1]
                dp[s][s+i-1] = max( dp[s][b] +dp[b+1][s+i-1], dp[s][s+i-1] );
            }
            dp[s][s+i-1] =max(dp[s][s+i-1] , abs(dp[s][s] - dp[s+i-1][s+i-1])*(i));
        }
    }
    cout  << dp[1][n];
    return 0;
}
