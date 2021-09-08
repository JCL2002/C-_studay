#include<bits/stdc++.h>
using namespace std;
char pic[503][503];
int num[503][503];
int n,m;
int main()
{
    int t;
    cin >>t;
    while(t--) {
    cin >> n >> m ;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m+1;j++)
        {
            pic[i][j]=0;
            num[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin >> pic[i][j] ;
    }
//    cout << n <<"  " << m <<endl;
    for(int i=n;i>0;i--)
    {
//        cout << n <<"  " << m <<endl;
        for(int j=1;j<=m;j++)
        {
            if(pic[i][j]=='*')
            {
//                cout <<"asadasd"<<endl;
                if(num[i+1][j-1]==num[i+1][j] && num[i+1][j]==num[i+1][j+1])
                {
                    num[i][j]=num[i+1][j]+1;
                }
                else
                {
                    num[i][j]=min(min(num[i+1][j-1],num[i+1][j]),num[i+1][j+1])+1;
                }
            }
            else
            {
                num[i][j]=0;
            }
        }
    }
//    cout <<"eddqd"<<endl;
//    cout << n <<"  " << m <<endl;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
//            cout << num[i][j]<< " : ";
            sum+=num[i][j];
        }
    }

//
    cout << sum <<endl;
    }
    return 0;
}
