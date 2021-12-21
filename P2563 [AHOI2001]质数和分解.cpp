#include<bits/stdc++.h>
using namespace std;
int dp[202]={1,};
vector<int>prime;
int n;
void gp()
{
    for(int i=2;i<=200;i++)
    {
        bool flag=0;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(!flag) prime.push_back(i);
    }
}
void init()
{
    gp();
    for(int x:prime)
    {
        for(int i=x;i<=200;i++) dp[i]+=dp[i-x];
    }
}
int main()
{
    init();
    while(cin >> n) cout << dp[n] << endl;
    return 0;
}
