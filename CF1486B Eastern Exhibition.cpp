#include<bits/stdc++.h>
using namespace std;
int x[1003];
int y[1003];
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        if(n&1)
        {
            for(int i=1;i<=n;i++) cin >>x[i] >>y[i];
            cout <<1<<endl;
            continue;
        }
        else
        {
            for(int i=1;i<=n;i++) cin >>x[i] >>y[i];
            sort(x+1,x+1+n);sort(y+1,y+1+n);
            cout <<(long long) (x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1)<<endl;
        }
    }
    return 0;
}
