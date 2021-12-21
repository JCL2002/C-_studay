#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=2;i<=1+n;i++) cout << i << " ";
        cout << endl;
    }
    return 0;
}
