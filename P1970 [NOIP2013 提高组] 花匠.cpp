#include<bits/stdc++.h>
using namespace std;
int n,arr[100005];
int ans=1;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i] ;
    int up=-1;
    for(int i=2;i<=n;i++)
    {
        if(up==-1)
        {
            if(arr[i]>arr[i-1]) ans++,up=1;
            if(arr[i] < arr[i-1] ) up=0,ans++;
        }
        else if(up==0){if(arr[i] > arr[i-1]) ans++,up=1;}
        else if(up ==1){if(arr[i] < arr[i-1]) ans++,up=0;}
    }
    cout << ans;
    return 0;
}
