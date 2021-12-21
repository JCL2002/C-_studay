#include<bits/stdc++.h>
using namespace std;
long long a,b,x;
int t;
bool flag;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> x;
        flag=0;
        while(a && b)
        {
            if(x>a && x>b)
            {
                cout << "NO\n";
                flag=1;
                break;
            }
            if(x==a || x==b || x == 0)
            {
                cout << "YES\n" ;
                flag=1;
                break;
            }
            if( (max(a,b)-x)%min(a,b) == 0ll )
            {
                cout << "YES\n";
                flag=1;
                break;
            }
            long long A=max(a,b);
            long long B=min(a,b);
            A%=B;
            a=A;
            b=B;
        }
        if(!flag) cout << "NO" << endl;
    }
    return 0;
}
