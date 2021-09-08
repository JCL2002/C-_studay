#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,u,r,d,l;
        cin >>n>>u>>r>>d>>l;
        bool flag=1;
        if((u<n-1&&d==n-1)||(u==n-1&&d<n-1))
        {
            if(r+l==0) flag=0;
        }
        else if((u<n-1&&d==n)||(u==n&&d<n-1))
        {
            if(l==0||r==0) flag=0;
        }
        else if(u==n-1&&d==n-1)
        {
            if(l+r<2) flag=0;
        }
        else if((u==n-1&&d==n)||(u==n&&d==n-1))
        {

            if(!((l>1&&r>0)||(l>0&&r>1))) flag=0;

        }
        else if(u==n&&d==n)
        {
            if(l<2||r<2) flag=0;
        }


        if((l<n-1&&r==n-1)||(l==n-1&&r<n-1))
        {
            if(u+d==0) flag=0;
        }
        else if((l<n-1&&r==n)||(l==n&&r<n-1))
        {
            if(u==0||d==0) flag=0;
        }
        else if(l==n-1&&r==n-1)
        {
            if(u+d<2) flag=0;
        }
        else if((l==n-1&&r==n)||(l==n&&r==n-1))
        {
            if(!((u>1&&d>0)||(d>1&&u>0))) flag=0;
        }
        else if(l==n&&r==n)
        {
            if(u<2||d<2) flag=0;
        }
        if(flag) cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}
