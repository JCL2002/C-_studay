#include<bits/stdc++.h>
using namespace std;
int k,n;
__int128 dp[1003];
void write(__int128 x)
{
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> k;
    dp[0]=1;
    for(int i=1;i<=k;i++)
        for(int j=i;j<=n;j++) dp[j] += dp[j-i];
    write(dp[n]);
    return 0;
}
