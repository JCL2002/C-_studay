#include<bits/stdc++.h>
using namespace std;
int n;
int arr[2003];
vector<int>LIS;
int main()
{
    cin.sync_with_stdio(false);
    while(cin >> n)
    {
        for(int i=1;i<=n;i++) cin >> arr[i];
        LIS.clear();
        for(int i=n;i;i--)
        {
            if((int)(lower_bound(LIS.begin(),LIS.end(),arr[i])-LIS.begin())==(int)LIS.size()) LIS.push_back(arr[i]);
            else *lower_bound(LIS.begin(),LIS.end(),arr[i])=arr[i];
        }
        if(LIS.size()>2) cout << "No!\n";
        else cout <<"Yes!\n";
    }
    return 0;
}
