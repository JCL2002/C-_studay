#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c;
int main()
{
    cin >>t;
    while(t--)
    {
        cin >> a >> b >> c;
        cout << ((a+b+c)%3!=0) << endl;
    }
    return 0;
}
