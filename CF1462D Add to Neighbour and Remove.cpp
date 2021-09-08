#include<bits/stdc++.h>
using namespace std;
int arr[3003];
int t,n;
int main()
{
    cin >> t ;
    while(t--)
    {
        cin >> n ;
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i] ;
        }
        int aim=0;
        int times=0;
        int ans=1e9+7;
        for(int i=1;i<=n;i++)
        {
            aim+=arr[i];
            int sum=0;
            times=0;
            for(int j=1;j<=n;j++)
            {
                sum+=arr[j];
                if(sum==aim)
                {
                    sum=0;
                    times++;
                }
            }
            if(sum==0) ans=min(ans,n-times);
        }
        cout << ans <<endl;
    }
    return 0;
}
