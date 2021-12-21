#include<bits/stdc++.h>
using namespace std;
int t;
char s[10];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> s;
        int len=strlen(s);
        if( (int) (s[len-1]-'0') %2 ==0)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            if((int) (s[0]-'0') % 2 == 0) cout << 1 << endl;
            else
            {
                bool flag=0;
                for(int i=0;i<len;i++) if( (int) (s[i]- '0') % 2 ==0) flag=1;
                if(flag) cout << 2 << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}
