#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if((x+y)&1)
        {
            cout << "-1 -1\n";continue;
        }
        else
        {
            if(x>y)
            {
                cout << (x+y)/2 << " " << 0 << endl;
            }
            else
            {
                cout << 0 << " " << (x+y)/2 << endl;
            }
        }
    }
    return 0;
}
