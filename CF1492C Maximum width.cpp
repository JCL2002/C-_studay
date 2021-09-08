#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200005];
char t[200005];
int sum[200005];
int mus[200005];
int main()
{
    cin >>n>>m;
    cin >>s;
    cin >>t;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[j])
        {
            sum[j]=i;
            j++;
        }
        if(j==m) break;
    }
    j--;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==t[j])
        {
            mus[j]=i;
            j--;
        }
        if(j<0) break;
    }
    int ans=0;
    for(int i=1;i<m;i++)
    {
        ans=max(ans,mus[i]-sum[i-1]);
    }
    cout <<ans;
    return 0;
}
