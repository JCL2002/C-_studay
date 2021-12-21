#include<bits/stdc++.h>
using namespace std;
string s,t;
vector<string> dic;
int dp[500];
int main()
{
    cin.sync_with_stdio(false);
    cin >> s;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> t;
        dic.push_back(t);
    }
    for(int i=1;i<=(int)s.size();i++)
    {
        dp[i]=dp[i-1];
        for(auto x : dic)
        {
            if((int)x.size() < i+1)
            {
                bool flag=1;
                for(int j=0;j<(int)x.size();j++)
                {
                    if(x[x.size()-j-1]!=s[i-j-1])
                    {
                        flag=0;
                        break;
                    }
                }
//                cout << "debug " << flag << endl;
                if(flag) dp[i] = max(dp[i],dp[i-x.size()]+1);
            }
        }
    }
    cout << dp[s.size()];
    return 0;
}
