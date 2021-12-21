#include<bits/stdc++.h>
using namespace std;
int n,k,d,s;
int f[103][103];
struct node{
    int t,z;
}a[103];
int main(){
    memset(f,10,sizeof(f));
    cin>>n>>k>>d>>s;
    for(int i=1;i<=n;i++)cin>>a[i].t>>a[i].z;
    f[0][0]=0;
    for(int i=1;i<=k;i++)
        for(int j=0;j<=n;j++){
            f[i][j]=f[i-1][j];
            for(int k=0;k<=min(j,a[i].z);k++)
                f[i][j]=min(f[i-1][j-k]+k*a[i].t+d,f[i][j]);
        }
    if(f[k][n]>=10000)cout<<"impossible";
    else cout<<f[k][n];
    return 0;
}
