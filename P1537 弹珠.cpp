#include<bits/stdc++.h>
using namespace std;
int w[7];
int i;
int sum;
bool dp[100005];
vector<int>iteam;
int main()
{
    cin.sync_with_stdio(false);
    while(1)
    {
        i++;
        sum=0;iteam.clear();
        for(int i=1; i<=6; i++)
        {
            cin >> w[i] ,sum+=w[i]*i;
            for(int j=1;j<=w[i];j++) iteam.push_back(i);
        }
        if(!sum) break;
        if(sum&1)
        {
            cout << "Collection #" << i << ":\n"<< "Can't be divided.\n\n";
            continue;
        }
        memset(dp,0,sizeof(int)*(sum/2+2));
        dp[0]=1;
        for(auto x : iteam)
            for(int j=sum/2;j>=x;j--) dp[j] += dp[j-x];
        if(dp[sum/2])
        {
            cout << "Collection #" << i << ":\n"<< "Can be divided.\n\n";
            continue;
        }
        cout << "Collection #" << i << ":\n"<< "Can't be divided.\n\n";
    }
    return 0;
}
