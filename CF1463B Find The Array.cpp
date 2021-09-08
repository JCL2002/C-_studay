#include<bits/stdc++.h>
using namespace std;
int arr[55];
int times[31];
int beauty[55];
int t,n;
void init()
{
    int base=1;
    for(int i=0;i<=30;i++)
    {
        times[i]=base;
        base*=2;
    }
}
int main()
{
    init();
//    for(int i=0;i<=30;i++) cout << times[i] << "  ";
    cin >> t ;
    while(t--)
    {
        cin >> n ;
        for(int i=1;i<=n;i++) cin >> arr[i] ;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=30;j++)
            {
                if(times[j]>arr[i]/2 && times[j]<=arr[i]+arr[i]/2)
                {
                    beauty[i]=times[j];
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++) cout << beauty[i] << " ";
        cout << endl ;
    }
    return 0;
}
