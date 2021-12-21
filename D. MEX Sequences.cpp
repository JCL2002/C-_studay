#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int t,n,u;
int num[500005];
int sub[500005];
int arr[500005];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(num,0,sizeof(int)*(n+2));
        memset(sub,0,sizeof(int)*(n+2));
        for(int i=1; i<=n; i++) cin >> arr[i];
        long long ans=0ll;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==0ll)
            {
                ans = (ans + sub[0] +1 )%mod;
                sub[0] = (2*sub[0] +1) % mod;
                cout << "debug " << sub[0] << endl;
            }
            else if(arr[i]==1ll)
            {
                ans = (ans + sub[0] +1) % mod;
                ans = (ans + sub[1]  )% mod;

                sub[1] = (2*sub[1] + sub[0] +1)% mod;
                cout << "debug " << sub[1] << endl;
            }
            else
            {
                ans = ( ans + sub[ arr[i]-1 ]  )% mod;
                ans = (ans + sub[ arr[i] ]) % mod;
                ans = (ans + sub[ arr[i] -2]) % mod;
                sub[arr[i]] = (sub[arr[i] ] + sub[arr[i]] )% mod;
                sub[arr[i]] = (sub[arr[i] ] + sub[arr[i]-1] )% mod;
//                sub[arr[i]] = (sub[arr[i] ] + sub[arr[i]-2] )% mod;
                cout << "debug " << sub[ arr[i] ] << endl;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
