#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 14233333 ;

int n;
int a=1,b=2,c;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    if(n==1) cout << 1 ;
    else if(n==2) cout << 2 ;
    else
    {
        for(int i=3; i<=n; i++)
        {
            c=(b+(i-1)*a)%mod;
            a=b;
            b=c;
        }
        cout << c;
    }
    return 0;
}
