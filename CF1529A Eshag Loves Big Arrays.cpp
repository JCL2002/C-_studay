#include<bits/stdc++.h>
using namespace std;
int arr[103];
int t,n;
int main()
{
    cin >>t;
    while(t--)
    {

        cin >>n;
        for(int i=1;i<=n;i++) cin >>arr[i];
        sort(arr+1,arr+1+n);
        int num=0;
        int first=arr[1];
        for(int i=1;i<=n;i++) if(arr[i]>first) num++;
        cout <<num<<endl;
    }
    return 0;
}
