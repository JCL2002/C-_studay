#include<bits/stdc++.h>
using namespace std;
int n,i,j;
int main()
{
    cin >>n>>i>>j;
    int N=n;
    int res=0;
    int cover=min(min(min(i,j),N-i+1),N-j+1);//外边包裹的圈数
//    cout <<cover<<endl;
    for(int i=1;i<=cover-1;i++)
    {
        res+=n*4-4;
        n-=2;
    }
    if(i==cover)//在第一行
    {
//        cout <<"第一行"<<endl;
        res+=j-cover+1;
    }
    else if(j==(N-cover)+1)//在最后一列
    {
//        cout <<"最后一列"<<endl;
        res+=(n+i-cover);
    }
    else if(i==(N-cover+1))
    {
//        cout <<"最后一行"<<endl;
        res+=(2*n-1-j+(N-cover)+1);
    }
    else//第一列
    {
        res+=(3*n-2+(N-cover)-i+1);
    }
    cout <<res;
    return 0;
}
