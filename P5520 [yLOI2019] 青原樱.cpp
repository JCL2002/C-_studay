#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,ans=1;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> n >> m >> p;
    for(int i=n-m+1;i>=n-2*m+2;i--) ans = (ans*i) % p;
    cout << ans;
    return 0;
}
