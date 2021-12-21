#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int ans[200];
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        memset(ans,0,sizeof(int)*(n+2));
        if(a>n/2+1 || (a<=n/2 && b<=n/2) || (a==n/2+1) && b!=n/2)
        {
            cout << -1 << endl; continue;
        }
        else
        {
            ans[1]=a;ans[n/2+1]=b;
            int j=2;
            for(int i=n;i>0;i--)
            {
                if(!ans[j] && i!=a && i!=b) ans[j++]=i;
                else if(ans[j]) j++,i++;
            }
            for(int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
