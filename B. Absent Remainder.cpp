
#include<bits/stdc++.h>
using namespace std;
int t,n;
int arr[200005];
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i];
        sort(arr+1,arr+1+n);
        for(int i=2;i<=n/2+1;i++)
        {
            cout << arr[i] << " " << arr[1] << "\n";
        }
    }
    return 0;
}
