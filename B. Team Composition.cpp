#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b;
signed main()
{
    cin.sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a >= 3*b) cout << b << endl;
        else if(b >=3*a) cout << a << endl;
        else
        {
            int e=max(a,b) - min(a,b);
            cout << e/2 + (min(a,b)-e/2) /2 << endl;
        }
    }
    return 0;
}
