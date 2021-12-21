#include<bits/stdc++.h>
using namespace std;
int fst[2000006];
int ans,sum=1000002;
char s[1000006];
int main()
{
    cin.sync_with_stdio(false);
    cin >>s+1;
    int len=strlen(s+1);
    fst[sum]=1;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='G') sum++;
        else sum--;
        if(fst[sum]) ans=max(ans,i+1-fst[sum]);
        else fst[sum]=i+1;
    }
    cout << ans;
    return 0;
}
