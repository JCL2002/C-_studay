#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
int n,t;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> t;
        if((int)(lower_bound(arr.begin(),arr.end(),t)-arr.begin())==(int)arr.size())arr.push_back(t);
        else *lower_bound(arr.begin(),arr.end(),t)=t;
    }
    cout << n-arr.size();
    return 0;
}
