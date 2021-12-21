#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[155];
int now1=-1;int now2=-1;int ans;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(now1<=arr[i].first)
        {
            ans++;now1=arr[i].second;
        }
        else if(now2<=arr[i].first)
        {
            ans++;now2=arr[i].second;
            swap(now1,now2);
        }
    }
    cout <<ans;
    return 0;
}
