#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        if(n<5) cout <<0<<endl;
        else cout <<((int)sqrt(2*n-1)-3)/2+1<<endl;
    }
    return 0;
}
