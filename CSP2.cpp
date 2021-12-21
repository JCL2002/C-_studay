#include<bits/stdc++.h>
using namespace std;
int n,N,r;
int arr[100005];
long long sum;
int g(int x)
{
    return x/r;
}
int Next(int x)
{
    return (x/r+1) * r -x;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> N;
    r=N/(n+1);
    for(int i=1;i<=n;i++) cin >> arr[i];
    arr[n+1]=N;
    int index=0;
    for(int i=0;i<=n;i++)
    {
        while(index<arr[i+1])
        {
            sum += min(r,min(arr[i+1]-index,Next(index))) * abs(g(index)-i);
            index += min(r,min(arr[i+1]-index,Next(index)));
        }
    }
    cout << sum;
    return 0;
}
