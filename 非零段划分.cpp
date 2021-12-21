#include<bits/stdc++.h>
using namespace std;
int p[10004];//²î·ÖÊý×é
int n,last,u,sum;
int mmax;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> u;
        if(u>last)
        {
            p[last+1] ++;
            p[u+1] --;
        }
        last=u;
    }
    for(int i=1;i<=10003;i++)
    {
        sum+=p[i];
        mmax=max(mmax,sum);
    }
    cout << mmax;
    return 0;
}
