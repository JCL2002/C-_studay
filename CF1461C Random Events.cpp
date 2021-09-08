#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int brr[100005];
int n,m;
int main()
{
    int t;
    cin >> t ;
    while(t--)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i];
            brr[i]=arr[i];
        }
        sort(brr+1,brr+1+n);
        int range=n;
        while(brr[range]==arr[range]&&range) range--;
        int r;
        double poss,without=1.0d;
        for(int i=1;i<=m;i++)
        {
            cin >> r >> poss ;
            if(r>=range)
            {
                without*=(1.0d-poss);
            }
        }
        if(range==0) without=0.0d;
        printf("%.7f\n",1.0d-without);
    }
    return 0;
}
