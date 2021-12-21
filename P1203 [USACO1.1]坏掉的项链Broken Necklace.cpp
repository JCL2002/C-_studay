#include<bits/stdc++.h>
using namespace std;
int n;
char s[400];
char test[400];
int main()
{
    cin >> n;
    cin >> s;
    int ans=2;

    for(int i=0;i<n;i++)
    {
        strcpy(test,s);
        int num=2;
        int l=4*n+i-2;
        int r=4*n+i+1;
//        cout << (l%n) << " " << (r%n) << endl;
        while(num<n)
        {
            if(test[r%n]==test[(r-1)%n] || test[(r-1)%n]=='w')
            {
                num++;
                r++;
                continue;
            }
            if(test[r%n]=='w')
            {
                test[r%n]=test[(r-1)%n];
                num++;
                r++;
                continue;
            }
            break;
        }
        while(num<n)
        {
            if(test[l%n]==test[(l+1)%n] || test[(l+1)%n]=='w')
            {
                num++;
                l--;
                continue;
            }
            if(test[l%n]=='w' )
            {
                test[l%n]=test[(l+1)%n];
                num++;
                l--;
                continue;
            }
            break;
        }
//        cout << num << endl;
        ans=max(ans,num);
    }
    cout << ans;
    return 0;
}
