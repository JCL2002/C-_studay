#include<bits/stdc++.h>
using namespace std;
long long ans[1003];
long long sum[1003];
long long arr[1003];
int n,t;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> t;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]= ans[i-1]+ arr[i]*n*n;
        for(int j=0;j<i-1;j++)
        {
            if((arr[j+1]+arr[i])<=t) ans[i] =min(ans[i],ans[j]+(arr[i]+arr[j+1])*(sum[i]-sum[j]));
        }
    }
    cout << ans[n];
    return 0;
}
