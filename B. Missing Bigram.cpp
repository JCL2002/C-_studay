#include<bits/stdc++.h>
using namespace std;
int t,n;
string s[106];
vector<char> ans;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n-2;i++) cin >> s[i];
        ans.clear();
        ans.push_back(s[1][0]);
        ans.push_back(s[1][1]);
        for(int i=2;i<=n-2;i++)
        {
            if(s[i][0]==s[i-1][1]) ans.push_back(s[i][1]);
            else
            {
                ans.push_back(s[i][0]);
                ans.push_back(s[i][1]);
            }
        }
        if(ans.size()<n) ans.push_back('a');
        for(auto x : ans) cout << x;
        cout << endl;
    }
    return 0;
}
