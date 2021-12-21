#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l;
struct node
{
    int x;
    int y;
};
node arr[10005];
int x0,Y0;
int t;
signed main()
{
    cin >> n >> l;
    for(int i=1;i<=n;i++)
    {
        cin >> t ;
        if(i&1)
        {
            arr[i].x=x0;
            arr[i].y=t;
            Y0=t;
        }
        else
        {
            arr[i].x=t;
            arr[i].y=Y0;
            x0=t;
        }
    }
    int sum=0;
    cout << "0 0" << endl;
    for(int i=1;i<=n;i++)
    {
        if(i&1)//竖直方向
        {
            if(l-sum>abs(arr[i].y-arr[i-1].y))
            {
                sum+=abs(arr[i].y-arr[i-1].y);
                continue;
            }
            else if(l-sum == abs(arr[i].y-arr[i-1].y))
            {
                if(arr[i].x || arr[i].y)cout << arr[i].x << " " << arr[i].y << endl;
                sum=0;
                continue;
            }
            else
            {
                if(arr[i].y>arr[i-1].y && (arr[i-1].y+l-sum ||arr[i-1].x )) cout << arr[i-1].x << " " << arr[i-1].y+l-sum << endl;
                else if(arr[i-1].y-l+sum ||arr[i-1].x ) cout << arr[i-1].x << " " << arr[i-1].y-l+sum << endl;
//                exit(1);
                sum=-(l-sum);
                i--;
                continue;
            }
        }
        else//水平方向
        {
            if(l-sum>abs(arr[i].x-arr[i-1].x))
            {
                sum+=abs(arr[i].x-arr[i-1].x);
                continue;
            }
            else if(l-sum == abs(arr[i].x-arr[i-1].x))
            {
                if(arr[i].x || arr[i].y) cout << arr[i].x << " " << arr[i].y << endl;
                sum=0;
                continue;
            }
            else
            {
//                cout << "sss";
                if(arr[i].x>arr[i-1].x && (arr[i-1].x+l-sum || arr[i-1].y)) cout << arr[i-1].x+l-sum << " " << arr[i-1].y << endl;
                else if(arr[i-1].x-l+sum ||arr[i-1].y ) cout << arr[i-1].x-l+sum << " " << arr[i-1].y << endl;
//                exit(1);
                sum=-(l-sum);
                i--;
                continue;
            }
        }
    }
    return 0;
}
