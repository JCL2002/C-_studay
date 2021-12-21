#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int power(int i)
{
    int sum=1,base=2;
    while(i)
    {
        if(i&1ll) sum=(sum*base)%mod;
        i >>= 1ll;
        base=(base*base)%mod;
    }
    return sum;
}
int t,n,m;
int rubbish;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int sum=0ll;
        for(int i=1;i<=m;i++) cin >> rubbish >> rubbish >> rubbish,sum |=rubbish;
        cout << (sum * power(n-1))%mod << endl;
    }
    return 0;
}
