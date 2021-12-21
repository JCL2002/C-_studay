#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> k;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long hight=k/i;
        long long mod=k%i;
        if(hight>m ||(hight==m && mod>0))continue;
        ans = max(ans, (i*(i-1)/2*hight*(hight-1)/2+hight*(hight+1)/2*mod*(mod-1)/2-hight*(hight-1)/2*mod*(mod-1)/2) );
    }
    for(int i=1;i<=m;i++)
    {
        long long hight=k/i;
        long long mod=k%i;
        if(hight>n ||(hight==n && mod>0))continue;
        ans = max(ans, (i*(i-1)/2*hight*(hight-1)/2+hight*(hight+1)/2*mod*(mod-1)/2-hight*(hight-1)/2*mod*(mod-1)/2) );
    }
    cout << ans;
    return 0;
}
