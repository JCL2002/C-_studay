#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int ans=0;
        ans+=(n+1)/2;
//        cout <<ans<<endl;
        int x=(n-1)/3;
        if(3*x+1<=n) x++;
        if(x%2ll==0) x++;
        ans+=(n-x)/2+1;
        cout <<ans<<endl;
    }
}
