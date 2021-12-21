#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int arr[105];
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> arr[i];
        sort(arr+1,arr+1+n);
        long long score=0;
        for(int i=1;i<=k;i++)
        {
            if(arr[n-i+1]==arr[n-i-k+1]) score++;
            arr[n-i+1]=0;arr[n-i-k+1]=0;
        }
        for(int i=1;i<=n;i++) score+=arr[i];
        cout << score << endl;
    }
    return 0;
}
