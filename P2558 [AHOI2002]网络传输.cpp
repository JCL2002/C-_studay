#include<bits/stdc++.h>
using namespace std;
int k,p;
__int128 power(__int128 a,__int128 x)
{
    __int128 sum=1;
    while(x)
    {
        if(x&(__int128)1) sum=sum*a;
        x >>=1;
        a*=a;
    }
    return sum;
}
__int128 ans;
void PR(__int128 x)
{
    stack<int>s;
    while(x)
    {
        s.push(x%10);
        x/=10;
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> k >> p;
    for(int i=0;i<=12;i++)
    {
        if(p&1<<i) ans+=power(k,i);
    }
    PR(ans);
    return 0;
}
