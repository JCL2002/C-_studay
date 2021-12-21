#include<bits/stdc++.h>
using namespace std;
bool dp[1003];
vector<int>w;
int n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) w.push_back(1);
    cin >> n;
    for(int i=1;i<=n;i++) w.push_back(2);
    cin >> n;
    for(int i=1;i<=n;i++) w.push_back(3);
    cin >> n;
    for(int i=1;i<=n;i++) w.push_back(5);
    cin >> n;
    for(int i=1;i<=n;i++) w.push_back(10);
    cin >> n;
    for(int i=1;i<=n;i++) w.push_back(20);
    dp[0]=1;
    for(int x:w)
    {
        for(int i=1000;i>=x;i--) dp[i]+=dp[i-x];
    }
    int num=0;
    for(int i=1;i<=1000;i++) if(dp[i]) num++;
    cout << "Total=" << num;
    return 0;
}
