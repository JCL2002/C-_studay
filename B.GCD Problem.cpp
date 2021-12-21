#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n&1ll)
        {
            if((n-1)/2%2) cout << (n-1)/2-2 << " " << (n-1)/2+2 << " 1\n";
            else cout << (n-1)/2-1 << " " << (n-1)/2+1 << " 1\n";
        }
        else cout << (n-1)/2 << " " << (n-1)/2+1 << " 1\n";
    }
    return 0;
}
