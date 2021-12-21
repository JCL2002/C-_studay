#include<bits/stdc++.h>
using namespace std;
bool dp[103][10003];
vector<int>cb[103];
int n,t;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) while(cin >> t && t!=-1) cb[i].push_back(t);
    for(int i=1; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=n; i++)
        for(int j:cb[i])
            for(int k=10000; k>=j; k--) dp[i][k] += dp[i][k-j];
    int mmax=0;
    for(int i=1;i<=10000;i++)
    {
        bool flag = 1;
        for(int j=1;j<=n;j++)
        {
            if(!dp[j][i])
            {
                flag=0;
                break;
            }
        }
        if(flag) mmax=i;
    }
    cout << mmax;
    return 0;
}
