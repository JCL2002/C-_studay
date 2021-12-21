#include<bits/stdc++.h>
using namespace std;
int n,q;
int f[100005][21];
int Log[100005];
int find_min(int l,int r)
{
    if(l==r) return f[l][0];
    return min(f[l][Log[r-l]],find_min(l+ (1 << (Log[r-l]) ) ,r));
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> f[i][0];
    for(int i=2;i<=n;i++) Log[i] = Log[i/2] + 1;
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n-(1 <<i)+1;j++)
            f[j][i] = min( f[j][i-1] ,f[ j+ (1 <<(i-1))  ][i-1]);

    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin >> l >> r;
        cout << find_min(l,r) << ' ';
    }
    return 0;
}
