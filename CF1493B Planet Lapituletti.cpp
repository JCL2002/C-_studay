#include<bits/stdc++.h>
using namespace std;
int mp[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
int a,b,c,d,A,B,C,D;
int h,m;
void mirror()
{
    //求镜像时间
    A=mp[a];
    B=mp[b];
    C=mp[c];
    D=mp[d];
}
bool test()
{
    //检测当前时间的镜像时间是否合法
    mirror();
    if(A<0||B<0||C<0||D<0) return 0;
    int hour=D*10+C;
    int minute=B*10+A;
    if(hour<h&&minute<m) return 1;
    return 0;
}
void tad()
{
    //时间增加一分钟
    int minute=c*10+d;
    int hour=a*10+b;
    minute++;
    hour+=minute/m;
    minute%=m;
    hour%=h;
    a=hour/10;
    b=hour%10;
    c=minute/10;
    d=minute%10;
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        cin >>h>>m;
        char s[6];
        cin >>s;
        a=s[0]-'0'; b=s[1]-'0';c=s[3]-'0';d=s[4]-'0';
        while(!test()) tad();
        cout <<a<<b<<":"<<c<<d<<endl;
    }
    return 0;
}
