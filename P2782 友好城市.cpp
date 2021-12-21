#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> city;
int n;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.first < b.first;
}
vector<int>LIS;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;int u,v;
    for(int i=1;i<=n;i++) cin >> u >> v,city.push_back({u,v});
    sort(city.begin(),city.end(),cmp);
    LIS.push_back(-1);
    for(auto x : city)
    {
        if( x.second > LIS[ LIS.size() -1 ] ) LIS.push_back(x.second);
        else LIS[ upper_bound( LIS.begin() , LIS.end() , x.second ) - LIS.begin()  ] = x.second;
    }
    cout << LIS.size()-1;
    return 0;
}
