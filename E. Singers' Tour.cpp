#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,sum;
int brr[400009];
int arr[400009];
signed main()
{
//    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0ll;
        for(int i=1;i<=n;i++) cin >> brr[i],sum+=brr[i];
        int Size = (n+1)*n/2;
        int x = sum / Size;
        if(Size*x!=sum)
        {
            cout << "NO" << endl;
            continue;
        }
        bool flag=1;
        for(int i=2;i<=n;i++)
        {
            arr[i]=(x+brr[i-1]-brr[i])/n;
            if(arr[i]*n!=(x+brr[i-1]-brr[i]))
            {
                flag=0;
                break;
            }
        }
        for(int i=2;i<=n;i++) x -= arr[i];
        arr[1]=x;
        if(flag) for(int i=1;i<=n;i++)
        {
            if(arr[i]<=0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout << "YES" << endl;
            for(int i=1;i<=n;i++) cout << arr[i] << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
