#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,ans=2,a[10005],b[10005];
void checkx()
{
    for(int i=2; i<=n+1; i++)
    {
        b[i]=a[i-1]-b[i-1]-b[i-2];
        if (!(b[i]==1||b[i]==0))
        {
            ans--;
            break;
        }
        if (i==n+1&&b[i]!=0)
        {
            ans--;
            break;
        }
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin>>n;
    b[0]=0;
    for (i=1; i<=n; i++) cin>>a[i];
    b[1]=1;
    checkx();
    b[1]=0;
    checkx();
    cout << ans;
    return 0;
}
