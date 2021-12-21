#include<bits/stdc++.h>
using namespace std;
int cf[1003][1003];
int n,k,ans,x_1,y_1,x_2,y_2;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        x_1++;x_2++;y_1++;y_2++;
        cf[x_1][y_1]++;
        cf[x_1][y_2]--;
        cf[x_2][y_1]--;
        cf[x_2][y_2]++;
    }
//    cout << "debug " << endl;
    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=1000; j++)
        {
//            cout << "debug : " << endl;
            cf[i][j] += cf[i-1][j] + cf[i][j-1] - cf [i-1][j-1] ;
            if(cf[i][j] == k) ans++;
        }
    }
    cout << ans;
    return 0;
}
