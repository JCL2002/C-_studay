#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
string tar="abc";
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        cin >> s >> t;
        sort(s.begin(),s.end());
        if(t==tar)
        {
            int A=0,B=0,C=0;
            for(int i=0;i<(int)s.length();i++)
            {
                if(s[i]=='a')A++;
                if(s[i]=='b')B++;
                if(s[i]=='c')C++;
            }
            if(A&& B&&C)
            {
                for(int i=1;i<=A;i++)
                {
                    cout << 'a';
                }
                for(int i=1;i<=C;i++)
                {
                    cout << 'c';
                }
                for(int i=1;i<=B;i++) cout << 'b';
                for(auto x:s)
                {
                    if(x!='a'&&x!='b'&&x!='c') cout << x;
                }
                cout << endl;
            }
            else cout << s << endl;
        }
        else cout << s << endl;
    }
    return 0;
}
