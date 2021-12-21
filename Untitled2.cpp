#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
const ll mod=1e9+7;
ll a[N],b[N];
int visa[N],visb[N];
array <ll,3> arr[N];
int main()
{
    int n,m;
    cin>>n>>m;
    ll suma=0,sumb=0;
    for(int i=1; i<=n; i++)
    {
       cin>>a[i];
       a[i]%=mod;
       suma+=a[i];
       suma%=mod;
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        b[i]%=mod;
        sumb+=b[i];
        sumb%=mod;
    }
    int k;
    cin>>k;
    for(int i=1; i<=k; i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        arr[i][2]%=mod;
    }
    __int128 ans=0;
    for(int i=k; i>=1; i--)
    {
        if(arr[i][0]==2)
        {
            if(visb[arr[i][1]]) continue;
            visb[arr[i][1]]=1;
            ans+=(b[arr[i][1]]%mod)*(suma%mod)%mod*arr[i][2]%mod;
            sumb=(sumb-b[arr[i][1]])%mod;
        }
        else{
            if(visa[arr[i][1]]) continue;
            visa[arr[i][1]]=1;
            ans+=a[arr[i][1]]*(sumb%mod)%mod*arr[i][2]%mod;
            suma=(suma-a[arr[i][1]])%mod;
        }
//        cout<<ans<<endl;
    }
    cout<<(ll) (ans%mod) <<endl;
    return 0;
}
/*
2 3
1 2
3 4 5
4
1 1 1
2 1 1
2 1 2
2 3 3
*/
