#include<bits/stdc++.h>
using namespace std;
int n;
int Next[105];
int ans[105];
int mmax,mmin;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cout << "? ";
        for(int j=1;j<=n;j++)
        {
            if(j==i) cout << 2 ;
            else cout << 1 ;
            cout << " ";
        }
        cout << endl;
        int tmp;
        cin >> tmp;
        if(tmp==0) mmax=i;
        else if(tmp<i) Next[tmp]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cout << "? ";
        for(int j=1;j<=n;j++)
        {
            if(j==i) cout << 1 ;
            else cout << 2 ;
            cout << " ";
        }
        cout << endl;
        int tmp;
        cin >> tmp;
        if(tmp==0) mmin=i;
        else if(tmp<i) Next[i]=tmp;
    }
    int m=n;
    while(mmax)
    {
        ans[mmax]=n--;
        mmax=Next[mmax];
    }
    cout << "! ";
    for(int i=1;i<=m;i++) cout << ans[i] << " ";
    return 0;
}
