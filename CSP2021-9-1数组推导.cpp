#include<bits/stdc++.h>
using namespace std;
int n,t,last;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    int mmin=0,mmax=0;
    for(int i=1;i<=n;i++)
    {
        cin >> t;
        if(t>last)
        {
            mmin+=t;
            mmax+=t;
            last=t;
        }
        else
        {
            mmax+=last;
        }
    }
    cout << mmax  << endl << mmin;
    return 0;
}
