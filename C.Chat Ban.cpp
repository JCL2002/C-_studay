#include<bits/stdc++.h>
using namespace std;
int t;
long long k,x;
long long lst;
long long ans;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> k >> x;
        ans=0ll;
        lst=( (long long) sqrt(1+8*x) -1 ) / 2;
        if(lst*(lst+1)/2 < x ) lst++;
        lst=min(lst,k);
//        cout << "debug: " << lst << endl;
        x-=( lst*(lst+1)/2 );
        if(x<=0)
        {
            cout << lst << endl;
            continue;
        }
        if(k*(k-1)/2 <=x)
        {
            ans+=k*(k-1)/2;
            cout << 2*k-1 << endl;
            continue;
        }
        long long tmp=( 2*k-1 - (long long) sqrt( (1-2*k)*(1-2*k) - 8*x ) )/2;
        if(tmp*(2*k-(tmp+1))/2<x) tmp++;
        tmp=min(tmp,k-1);
        cout << k+tmp << endl;
    }
    return 0;
}
