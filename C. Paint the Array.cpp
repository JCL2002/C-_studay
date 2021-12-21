#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int arr[105];
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i];
        int a=arr[1],b=arr[2];
        for(int i=3;i<=n;i+=2) a=gcd(a,arr[i]);
        for(int i=4;i<=n;i+=2) b=gcd(b,arr[i]);
        bool flag=1;
        for(int i=1;i<=n;i+=2)
        {
            if(arr[i]%b==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout << b << endl;
            continue;
        }
        flag=1;
        for(int i=2;i<=n;i+=2)
        {
            if(arr[i]%a==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout << a << endl;
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}
