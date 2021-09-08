#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        //思路：每一个点的出度等于入度，且使出入度尽可能多
        //每一个点与剩下n-1个点相连前(n-1)/2个点为出(赢)，后(n-1)/2为入（输），其余为无向边（平局）
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(j<=(n-1)/2)
                {
                    cout <<"1 ";
                }
                else if(j>=(n-(n-1)/2))
                {
                    cout <<"-1 ";
                }
                else cout <<"0 ";
            }
        }
        cout <<endl;
    }
    return 0;
}
