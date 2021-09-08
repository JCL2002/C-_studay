#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[103];
int n,k;
signed main()
{
    int t;
    cin >>t;
    while(t--)
    {
        cin >>n>>k;
        for(int i=0;i<n;i++) cin >>arr[i];
        int add=0,sum=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]*100>(sum+add)*k)
            {
                add+=(arr[i]*100-(sum+add)*k)/k;
                if(arr[i]*100>(sum+add)*k) add++;
//                cout << "add: "<<add<<endl;
            }
            sum+=arr[i];
        }
        cout <<add<<endl;
    }
    return 0;
}
