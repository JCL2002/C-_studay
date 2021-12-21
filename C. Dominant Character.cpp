#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[1000006];
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        bool flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='a' && s[i+1]=='a')
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            cout << 2 << endl;
            continue;
        }
        for(int i=0;i<n-2;i++)
        {
            if(s[i]=='a' && s[i+2]=='a')
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            cout << 3 << endl;
            continue;
        }
        for(int i=0;i<n-3;i++)
        {
            if(s[i]=='a' && s[i+3]=='a' && s[i+1]!=s[i+2])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            cout << 4 << endl;
            continue;
        }
        for(int i=0;i<n-6;i++)
        {
            if(s[i]=='a' && s[i+3]=='a' && s[i+6]=='a' && s[i+1] !=s[i+4])
            {
                flag=1;
                break;
            }
        }
        if(flag) cout << 7 << endl;
        else cout << -1 <<endl;
    }
    return 0;
}
