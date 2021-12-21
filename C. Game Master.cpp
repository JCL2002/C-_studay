#include<bits/stdc++.h>
using namespace std;
int n,t,c;
pair<int,int> arr[100005];
pair<int,int> brr[100005];
bool flag[100005];
int indeg[100005];
vector<int>edge[100005];
queue<int>q;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(indeg,0,sizeof(int)*(n+2));
        memset(flag,0,n+2);
        while(!q.empty()) q.pop();
        for(int i=1; i<=n; i++) edge[i].clear();
        for(int i=1; i<=n; i++) cin >> c,arr[i]= {c,i};
        for(int j=1; j<=n; j++) cin >> c,brr[j]= {c,j};
        sort(arr+1,arr+1+n);
        sort(brr+1,brr+1+n);
        for(int i=2; i<=n; i++) edge[ arr[i-1].second ].push_back( arr[i].second ),indeg[arr[i].second]++;
        edge[arr[n].second ].push_back(arr[n].second);indeg[arr[n].second]++;
        for(int i=2; i<=n; i++) edge[ brr[i-1].second ].push_back( brr[i].second ),indeg[brr[i].second]++;
        edge[ brr[n].second ].push_back( brr[n].second );indeg[brr[n].second]++;
        for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);
        while(!q.empty())
        {
            int s=q.front();
            q.pop();
            flag[s]=1;
            for(auto x : edge[s])
            {
                indeg[x]--;
                if(indeg[x]==0) q.push(x);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(flag[i]) cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
    return 0;
}

