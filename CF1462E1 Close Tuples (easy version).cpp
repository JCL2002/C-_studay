#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i];
        arr[n+1]=1e9+7;
        if(n<3)
        {
            cout << 0 << endl;
            continue;
        }
        sort(arr+1,arr+1+n);
        long long ans=0;
        for(int i=1;i<=n-2;i++)
        {
            int* bond=upper_bound(arr+1,arr+2+n,arr[i]+2);
            int num=bond-(arr+i);
            ans+=(long long) (num-2)*(num-1)/2;
        }
        cout << ans <<endl;
    }
    return 0;
}
