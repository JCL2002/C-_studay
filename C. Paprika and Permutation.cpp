#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,j;
int arr[200015];
bool vis[200015];
bool flag;
int num;
signed main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(vis,0,n+6);
        flag=1;j=0;num=0;
        for(int i=1;i<=n;i++) cin >> arr[i];
        sort(arr+1,arr+1+n);
        for(int i=1;i<=n;i++)
        {
            if(arr[i]<=n)
            {
                if(!vis[arr[i]])
                {
                    vis[arr[i]] =1;
                    arr[i]=-1;
                }
                else continue;
            }
        }
        for(int i=1;i<=n;i++) if(vis[i]) num++;
        sort(arr+1,arr+1+n);
        for(int i=num+1;i<=n;i++)
        {
            while(vis[++j]);
            if( (arr[i]-1)/2 < j)
            {
                flag=0;
                break;
            }
            vis[j]=1;
        }
        if(flag) cout << n-num << endl;
        else cout << "-1\n";
    }
    return 0;
}
