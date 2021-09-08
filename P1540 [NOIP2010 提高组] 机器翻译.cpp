#include<bits/stdc++.h>
using namespace std;
int mem[1003];
int mess[1003];
int si=0;//当前内存大小
int n,m;
int ti=0;//在如次数
bool contain(int x)
{
    for(int i=1;i<=si;i++) if(x==mem[i]) return 1;
    return 0;
}
void add(int x)
{
    for(int i=0;i<n;i++) mem[i]=mem[i+1];
    mem[m]=x;
}
int main()
{
    cin >>m>>n;
    for(int i=1;i<=n;i++) cin >>mess[i];
    for(int i=1;i<=n;i++)
    {
        if(contain(mess[i])) continue;
        else
        {
            if(si==m)
            {
                ti++;
                add(mess[i]);
            }
            else
            {
                ti++;
                si++;
                mem[si]=mess[i];
            }
        }
    }
    cout <<ti;
    return 0;
}
