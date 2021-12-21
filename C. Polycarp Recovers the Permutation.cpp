#include<bits/stdc++.h>
using namespace std;
#define int long long

int t,n;
int arr[200005];
deque<int>ans;
signed main()
{
    cin.sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i];
        ans.clear();
        if(arr[1]==n)
        {
            int l=2,r=n;
            ans.push_back(n);
            while(l<=r)
            {
                if(arr[l]<arr[r]) ans.push_front(arr[l++]);
                else ans.push_back(arr[r--]);
            }
        }
        else if(arr[n]==n)
        {
            int l=1,r=n-1;
            ans.push_back(n);
            while(l<=r)
            {
                if(arr[l]<arr[r]) ans.push_front(arr[l++]);
                else ans.push_back(arr[r--]);
            }
        }
        else
        {
            cout << -1 << endl;
            continue;
        }
        for(int x : ans) cout << x << " ";
        cout << endl;
    }
}
