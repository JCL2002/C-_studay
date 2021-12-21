#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,h;
int arr[105];
bool test(int k)
{
    int sum=k;
    for(int i=2;i<=n;i++)
    {
        sum+=min( arr[i]-arr[i-1] , k);
    }
    if(sum>=h) return 1;
    return 0;
}
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n  >> h;
        for(int i=1;i<=n;i++) cin >> arr[i];
        int l=1,r=h; int mid=(l+r)/2;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(test(mid))
            {
                if(test(mid-1))
                {
                    r=mid-1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                l=mid+1;
            }
        }
        cout << mid << "\n";
    }
    return 0;
}
