#include<bits/stdc++.h>
using namespace std;
char s[100005];
long long sum;
int i;
long long read(int i)//读取数值大小
{
    long long res=0;
    while(s[i]>='0'&&s[i]<='9')
    {
        res*=10;
        res+=(long long)(s[i]='0');
        i++;
    }
    return res;
}
int main()
{
    cin >>s;
    int len=strlen(s);
    long long right=0;
    long long ans=0;
    i=0;
    ans=read(i);
    while(i<len)
    {
        if(s[i++]=='+') ans+=read(i);
        else ans*=read()
    }
    return 0;
}
