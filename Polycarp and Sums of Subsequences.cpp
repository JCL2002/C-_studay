#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int arr[9];
int a,b,c;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        for(int i=1;i<=7;i++) cin >> arr[i];
        a=arr[1];
        c=arr[5]-a;
        b=arr[6]-c;
        cout << a << " " << b << " " << c<< endl;
    }
    return 0;
}
