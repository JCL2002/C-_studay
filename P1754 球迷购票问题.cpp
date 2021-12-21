#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[42][22];
int main()
{
    cin >> n;
    dp[0][0]=1;
    for(int i=1; i<=n << 1 ; i++)
        for(int j=0; j<=i && j <=n; j++)
        {
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j]+=dp[i-1][j+1];
        }
    cout << dp[n<<1][0];
    return 0;
}
