#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int ti[200005];
int n;
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        cin >>n;
        for(int i=1;i<=n;i++) cin >>arr[i];
        sort(arr+1,arr+1+n);
//        for(int i=1;i<=n;i++) cout <<arr[i]<<" ";
//        cout <<endl;
        arr[n+1]=-1;
        int before=1;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if(arr[i+1]!=arr[i])
            {
                ti[++num]=i+1-before;
                before=i+1;
            }
        }
//        for(int i=1;i<=num;i++) cout <<ti[i]<<" ";
//        cout <<endl;
        sort(ti+1,ti+1+num);
        memset(arr,0,sizeof(int)*n);
        for(int i=1;i<=num;i++) arr[ti[i]]++;
        int mmax=0;int sum=0;
        for(int i=1;i<=ti[num];i++)
        {
            mmax=max(mmax,i*(num-sum));
            sum+=arr[i];
        }
        cout <<n-mmax<<endl;
    }
    return 0;
}
