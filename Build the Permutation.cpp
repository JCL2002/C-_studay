#include<bits/stdc++.h>
using namespace std;
int n,t,a,b;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >>a >> b;
        if(a >(n-1)/2 || b>(n-1)/2 || abs(a-b) >1 || a+b > n-2)
        {
            cout << -1 << endl;
            continue;
        }
        if(a==b)//转弯偶数次(2*a)
        {
            int l=n-a-1,r=n;
            for(int i=0; i<=a; i++)
            {
                cout << r-- << " "<< l--<< " ";
            }
            while(l) cout << l-- << " ";
            cout << endl;
        }
        else if(a>b)//转弯奇数次，先升后降
        {
            int l=n-a,r=n;
            for(int i=1;i<=a;i++)
            {
                cout << l-- <<" " << r-- << " ";
            }
            while(l) cout << l-- << " ";
            cout << endl;
        }
        else
        {
            int l=1,r=n-a;
            for(int i=1;i<=b;i++)
            {
                cout << r++ <<" " << l++ << " ";
            }
            while(l<=n-a-1) cout << l++ << " ";
            cout << endl;
        }

    }
    return 0;
}
