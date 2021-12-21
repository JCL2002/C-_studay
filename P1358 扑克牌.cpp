#include<bits/stdc++.h>
using namespace std;
const int mod = 10007;
int n,m;
int arr[105];
int c[10004][103];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) c[i][0]=1;
    c[1][1]=1;
    for(int i=1;i<=m;i++) cin >> arr[i];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=min(i,100);j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    int ans=1;
    for(int i=1;i<=m;i++)
    {
        ans=(ans*c[n][ arr[i] ])%mod;
//        cout << "debug: " << n << "  " << arr[i] << "  " << c[n][ arr[i] ] << endl;
        n-=arr[i];
    }
    cout << ans;
    return 0;
}
