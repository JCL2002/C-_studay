#include<bits/stdc++.h>
using namespace std;
int up[3][30004];
int down[3][30004];
int n;
int arr[300004];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++)
    {
        up[0][i] = up[0][i-1] + (arr[i]!=1);
        up[1][i] = min( up[0][i-1] , up[1][i-1] ) + (arr[i]!=2);
        up[2][i] = min( min( up[0][i-1] , up[1][i-1] ) , up[2][i-1] ) + (arr[i]!=3);
    }
    for(int i=1;i<=n;i++)
    {
        down[2][i] = down[2][i-1] + (arr[i]!=3) ;
        down[1][i] = min( down[2][i-1] , down[1][i-1] ) + (arr[i]!=2);
        down[0][i] = min( min( down[0][i-1] , down[1][i-1] ) , down[2][i-1] ) +(arr[i]!=1);
    }
    int mmin=9999999;
    for(int i=0;i<3;i++) mmin=min(mmin,up[i][n]),mmin=min(mmin,down[i][n]);
    cout << mmin;
    return 0;
}
