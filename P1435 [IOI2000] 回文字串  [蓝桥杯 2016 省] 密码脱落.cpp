#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[1003][1003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> a;
    b=a;
    reverse(b.begin(),b.end());
    int n=a.length();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i-1]==b[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            else dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
    cout << n-dp[n][n];
    return 0;
}
