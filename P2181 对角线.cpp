#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long ans=0;
    int n;
    cin >>n;
    ans=(unsigned long long)n*(n-1)/2*(n-2)/3*(n-3)/4;
    cout <<ans;
}
