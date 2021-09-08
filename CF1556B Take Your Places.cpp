#include<bits/stdc++.h>
using namespace std;
int odd[100005];
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        int noo=0,noe=0;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            cin >>tmp;
            if(tmp&1)
            {
                noo++;
                odd[noo]=i;
            }
            else noe++;
        }
        if(abs(noo-noe)>1)//无法实现目标
        {
            cout <<-1<<endl;
            continue;
        }
        int ans=0;
        if(noe>noo)
        {
            for(int i=1,j=2;i<=noo;i++,j+=2)
            {
                ans+=abs(j-odd[i]);
            }
            cout <<ans<<endl;
        }
        else if(noo>noe)
        {
            for(int i=1,j=1;i<=noo;i++,j+=2)
            {
                ans+=abs(j-odd[i]);
            }
            cout <<ans<<endl;
        }
        else
        {
            int ans1=0,ans2=0;
            for(int i=1,j=1;i<=noo;i++,j+=2)
            {
                ans1+=abs(j-odd[i]);
            }
            for(int i=1,j=2;i<=noo;i++,j+=2)
            {
                ans2+=abs(j-odd[i]);
            }
            cout <<min(ans1,ans2)<<endl;
        }
    }
    return 0;
}
