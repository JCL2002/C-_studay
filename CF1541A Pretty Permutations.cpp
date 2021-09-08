#include<bits/stdc++.h>
using namespace std;
int arr[102];
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        for(int i=1;i<=n;i++) arr[i]=i;
        for(int i=2;i<=n;i+=2) swap(arr[i],arr[i-1]);
        if(n&1) swap(arr[n],arr[n-1]);
        for(int i=1;i<=n;i++) cout <<arr[i]<<" ";
        cout <<endl;
    }
    return 0;
}
