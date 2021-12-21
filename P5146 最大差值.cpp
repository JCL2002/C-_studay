#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,mmin,ans=-99999999999999ll,t;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n >> mmin;
    for(int i=2;i<=n;i++)
    {
        cin >> t;
        ans=max(t-mmin,ans);
        mmin=min(mmin,t);
    }
    cout << ans;
    return 0;
}
