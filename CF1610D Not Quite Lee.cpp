#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int odd,oe,ee,t;
const int mod = 1e9+7;
int power(int x)
{
    if(x<0) return 1;
    int base=2,sum=1;
    while(x)
    {
        if(x&1) sum =(sum*base)%mod;
        base=(base*base)%mod;
        x >>=1;
    }
    return sum;
}
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> t;
        if(t&1) odd++;
        else if(t%4) oe++;
        else ee++;
    }
//    cout << (power(n-odd)+power(oe-1))%mod;
    cout << "debug " << odd << "  " << oe << "  " << ee << endl;
    int ans=0;
    for(int i=1; i<=odd; i++) ans = (ans + power(n-i))%mod;
    ans=(ans + power(oe-1)*(power(ee)-1))%mod;
    cout << ans << endl;
    return 0;
}
