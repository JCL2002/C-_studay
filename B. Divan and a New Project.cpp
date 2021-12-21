#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
pair<int,int> arr[200005];
bool cmp(pair<int,int> a,pair<int,int>b)
{
    return a.first > b.first;
}
int ans[200005];
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i].first,arr[i].second=i;
        sort(arr+1,arr+1+n,cmp);
        int j=n/2+2;
        ans[0]=j;
        long long sum=0ll;
        for(int i=1;i<=n;i++)
        {
            if(i & 1)
            {
                ans[ arr[i].second ]= j-(i+1)/2;
                sum+= arr[i].first * (i+1)/2;
            }
            else
            {
                ans[ arr[i].second ] = j+i/2;
                sum+= arr[i].first * (i)/2;
            }
        }
        cout << 2*sum << endl;
        for(int i=0;i<=n;i++) cout  << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
