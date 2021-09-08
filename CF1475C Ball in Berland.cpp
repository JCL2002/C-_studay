#include<bits/stdc++.h>
using namespace std;
struct p
{
    int a;
    int b;
};
p pa[200005];
int num_a[200005];
int num_b[200005];
int a,b,k;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        memset(num_a,0,sizeof(int)*a+1);
        memset(num_b,0,sizeof(int)*b+1);
        for(int i=1;i<=k;i++)
        {
            cin >> pa[i].a;
            num_a[pa[i].a]++;
        }
        for(int i=1;i<=k;i++)
        {
            cin >> pa[i].b;
            num_b[pa[i].b]++;
        }
        long long res=(long long)k*(k-1)/2;
        long long cou =0;
        for(int i=1;i<=k;i++)
        {
            cou+=(num_a[pa[i].a]-1);
            cou+=(num_b[pa[i].b]-1);
        }
        cou /=2;
        cout << res-cou << endl;
    }
    return 0;
}
