#include<bits/stdc++.h>
using namespace std;
int n;
int arr[2003];
int brr[2003];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++) cin >> brr[i];
    sort(arr+1,arr+1+n,cmp);
    sort(brr+1,brr+1+n,cmp);
    int la=1,ra=n,lb=1,rb=n;
    int score=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[la]>brr[lb])
        {
            la++;lb++;
            score++;
        }
        else if(arr[la]==brr[lb])
        {
            if(arr[ra]>brr[rb])score++,ra--,rb--;
            else
            {
                if(arr[ra]<brr[lb]) score--;
                ra--,lb++;
            }
        }
        else
        {
            ra--;
            lb++;
            score--;
        }
    }
    cout << 200*score;
    return 0;
}
