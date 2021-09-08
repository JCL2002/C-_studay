#include<bits/stdc++.h>
using namespace std;
char s[100007];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        int len=strlen(s+1);
        int num=0;
        for(int i=2;i<=len;i++)
        {
            if(s[i]==s[i-1]||s[i]==s[i-2])
            {
                s[i]='.';
                num++;
            }
        }
        cout << num << endl ;
    }
    return 0;
}
