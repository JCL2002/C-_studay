#include<bits/stdc++.h>
using namespace std;
int maxl,n,bl;
bool dp[2][1003];
vector<int>c;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> bl >> maxl;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    dp[0][bl]=1;
    int j=0;
    for(int x:c)
    {
        j++;
        memset(dp[j%2],0,1002);
        for(int i=0;i<=maxl;i++)
        {
            if(i>=x) dp[j%2][i]+=dp[(j+1)%2][i-x];
            if(i+x<=maxl) dp[j%2][i]+=dp[(j+1)%2][i+x];
        }
    }
    int mmax=-1;
    for(int i=0;i<=maxl;i++) if(dp[j%2][i]) mmax=i;
    cout << mmax;
    return 0;
}
