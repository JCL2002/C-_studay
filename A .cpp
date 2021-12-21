#include<bits/stdc++.h>
using namespace std;
int t,n,l,r,k;
int arr[105];
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r >> k;
        for(int i=1;i<=n;i++) cin >> arr[i];
        sort(arr+1,arr+1+n);
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if( arr[i] >= l && arr[i] <= r && k >= arr[i])
            {
                num++;
                k-=arr[i];
            }
        }
        cout << num << endl;
    }
    return 0;
}
