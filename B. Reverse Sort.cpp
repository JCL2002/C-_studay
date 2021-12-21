#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[10000];
vector<int>ans;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        ans.clear();
        bool flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]>s[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            int l=0,r=n-1;
            while(l<r)
            {
                if(s[r]=='0')
                {
                    for(;l<r;l++)
                    {
                        if(s[l]=='1')
                        {
                            ans.push_back(l+1);
                            ans.push_back(r+1);
                            l++;
                            break;
                        }
                    }
                }
                r--;
            }
            sort(ans.begin(),ans.end());
            cout << 1 << endl << ans.size() << " ";
            for(auto x:ans) cout << x << " ";
            cout << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
