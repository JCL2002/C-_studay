#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Size 3000000000
int num[600006];
pair<int,int> range()
{
    int s,t;
    for(int i=0;i<=600000;i++) if(num[i]){s=i;break;}
    for(int i=0;i<=600000;i++) if(num[i]) t=i;
    return {s,t};
}
long double E(pair<int,int>range)//求期望
{
    long double sum=0;
    for(int i=range.first;i<=range.second;i++) sum+=(long double)num[i]/Size;
    return sum/(range.second-range.first+1);
}
long double D(long double E,pair<int,int>range)//求方差
{
    long double sum = 0.0dd;
    for(int i=range.first;i<=range.second;i++) sum += ((long double)num[i]/Size - E)*((long double)num[i]/Size - E);
    return sum/(range.second-range.first+1);
}
signed main()
{
    srand(time(NULL));
    for(register int i=1; i<=Size; i++) num[(rand()<<4)+rand()%16]++;
    cout << "均值： " << E(range()) <<endl;
    cout << "方差: " << D(E(range()),range());
}
