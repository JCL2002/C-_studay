#include<bits/stdc++.h>
using namespace std;
int num[5];
int w[22];
bool dp[1222];
int s;
int main()
{
    int sum=0;
    cin >> num[1] >> num[2] >> num[3] >> num[4];
    for(int i=1;i<=4;i++)
    {
        s=0;
        for(int j=1;j<=num[i];j++) cin >> w[j],s+=w[j];
        memset(dp,0,1221);
        dp[0]=1;
        for(int j=1;j<=num[i];j++)
            for(int k=s;k>=w[j];k--) dp[k]+=dp[k-w[j]];
        int mmin=s;
        for(int j=s;j>0;j--) if(dp[j]) mmin=min(mmin,max(j,s-j));
//        cout << "min: " << mmin << endl;
        sum+=mmin;
    }
    cout << sum;
    return 0;
}
