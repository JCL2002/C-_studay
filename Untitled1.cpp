#include<bits/stdc++.h>
using namespace std;
int t,n;
int x,y;
vector<pair<int,int>> arr;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> x >> y;
            arr.clear();
            arr.push_back({x,y});
        }
    }
    return 0;
}
