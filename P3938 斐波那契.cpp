#include<bits/stdc++.h>
using namespace std;
long long fib[63];
int m;
void init()
{
    fib[1]=fib[2]=fib[3]=1ll;
    for(int i=4; i<62; i++) fib[i]=fib[i-1]+fib[i-2];
}
int dep(long long x)//返回某个节点的深度
{
    return (int) (lower_bound(fib+1,fib+62,x)-fib) -2;
}
long long fa(long long x)//返回某个节点的父节点
{
    return x-fib[ dep(x) + 1 ];
}
int depth(long long x)
{
    if(x==1) return 1;
    return depth(fa(x))+1;
}
int main()
{
//    cin.sync_with_stdio(false);
    cin >> m;
    init();
    long long a,b;
    for(int i=1; i<=m; i++)
    {
        scanf("%lld %lld",&a,&b);
        if(depth(a)<depth(b)) swap(a,b);
        while(depth(a)>depth(b))
        {
            a=fa(a);

        }
        while(a!=b)
        {
            a=fa(a);
            b=fa(b);
        }
        printf("%lld\n",a);
    }
    return 0;
}
