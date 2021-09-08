#include<bits/stdc++.h>
using namespace std;
char s[20004];
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        cin >>s+1;
        int len=n/2;
        int l1,r1,l2,r2;
        r1=r2=n;
        l2=n-len+1;
        l1=n-2*len+1;
        for(int i=1;i+len-1<=n;i++)
        {
            if(s[i-1]=='0')
            {
                l2=i-1;l1=i;
                r1=r2=i+len-1;
                break;
            }
            if(s[i+len]=='0')
            {
                l1=l2=i;
                r2=i+len-1;r1=i+len;
                break;
            }
        }
        cout <<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    }
    return 0;
}
