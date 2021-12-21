#include<bits/stdc++.h>
using namespace std;
char s[1000006];
int l[1000006];
void solve(int i)
{
    if(s[i]=='(' || s[i]=='[') l[i]=i;
    else
    {
        int x=i;
        while(x!=l[x]) x=l[x];
        if((s[i]==')'&&s[x]=='(')||(s[i]==']'&&s[x]=='['))
        {
             l[i]=x-1;
             if(s[x-1]==')' || s[x-1]==']') l[i]=l[x-1];
        }
        else l[i]=i;
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        l[i]=i-1;
        solve(i);
    }
    int ans=0,I=0;
    for(int i=1;i<=n;i++)
    {
        if(i-l[i]>ans)
        {
            I=i;
            ans=i-l[i];
        }
    }
    for(int i=l[I]+1;i<=I;i++) cout << s[i];
    return 0;
}
//[()[[(([]))]]]()
//[()[[(([]))]]]()[[]()()()()][][][][][]
