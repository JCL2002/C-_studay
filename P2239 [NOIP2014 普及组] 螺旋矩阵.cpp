#include<bits/stdc++.h>
using namespace std;
int n,i,j;
int main()
{
    cin >>n>>i>>j;
    int N=n;
    int res=0;
    int cover=min(min(min(i,j),N-i+1),N-j+1);//��߰�����Ȧ��
//    cout <<cover<<endl;
    for(int i=1;i<=cover-1;i++)
    {
        res+=n*4-4;
        n-=2;
    }
    if(i==cover)//�ڵ�һ��
    {
//        cout <<"��һ��"<<endl;
        res+=j-cover+1;
    }
    else if(j==(N-cover)+1)//�����һ��
    {
//        cout <<"���һ��"<<endl;
        res+=(n+i-cover);
    }
    else if(i==(N-cover+1))
    {
//        cout <<"���һ��"<<endl;
        res+=(2*n-1-j+(N-cover)+1);
    }
    else//��һ��
    {
        res+=(3*n-2+(N-cover)-i+1);
    }
    cout <<res;
    return 0;
}
