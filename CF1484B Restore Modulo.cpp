#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[100005];
int n,m,s,c;
signed main()
{
    int t;
    cin >>t;
//    int T=t;
    while(t--)
    {
        cin >>n;
        for(int i=1;i<=n;i++) cin >>arr[i];
//        if(T==39972)
//        {
//            if(t==T-55)
//            {
//                for(int i=1;i<=n;i++) cout <<arr[i]<<" ";
//                cout <<endl;
//            }
//            else continue;
//        }
        c=0;//防止n=1
        m=-1;
        s=arr[1];
        for(int i=1;i<n;i++) if(arr[i+1]>=arr[i]) {c=arr[i+1]-arr[i];break;}
        if(c==0)
        {
            //判断是不是·等差数列
            bool flag=1;
            int d=arr[2]-arr[1];
            for(int i=3;i<=n;i++) if(arr[i]-arr[i-1]!=d){flag=0;break;}
            if(flag) cout <<0<<endl;
            else cout <<-1<<endl;
            continue;
        }
        int sum=s;
        for(int i=2;i<=n;i++)
        {
            sum+=c;
            if(sum>arr[i])//在此出现断层
            {
                m=sum-arr[i];
                break;
            }
        }
//        cout <<"测试："<<m<<"  "<<c<<endl;
        if(m==-1)//单调递增
        {
            //判断是不是·等差数列
            bool flag=1;
            int d=arr[2]-arr[1];
            for(int i=3;i<=n;i++) if(arr[i]-arr[i-1]!=d){flag=0;break;}
            if(flag) cout <<0<<endl;
            else cout <<-1<<endl;
            continue;
        }

        //验证以m为mod数是否成立
        bool flag=1;
        if(m<arr[1]) flag=0;
        sum=s;
        for(int i=2;i<=n;i++)
        {
            sum+=c;
            if(sum%m!=arr[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout <<m<<" "<<c<<endl;
        }
        else
        {
            cout <<-1<<endl;
        }
    }
    return 0;
}
