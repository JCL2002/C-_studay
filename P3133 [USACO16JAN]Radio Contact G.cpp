#include<bits/stdc++.h>
using namespace std;
char f[2003];
char b[2003];
int n,m,fx,fy,bx,by;
vector<pair<int,int> > F,B;
void init()
{
    int x,y;
    x=fx,y=fy;
    F.push_back({x,y});
    for(int i=0;i<n;i++)
    {
        if(f[i]=='N') y++;
        if(f[i]=='S') y--;
        if(f[i]=='E') x++;
        if(f[i]=='W') x--;
        F.push_back({x,y});
    }
    x=bx,y=by;
    B.push_back({x,y});
    for(int i=0;i<m;i++)
    {
        if(b[i]=='N') y++;
        if(b[i]=='S') y--;
        if(b[i]=='E') x++;
        if(b[i]=='W') x--;
        B.push_back({x,y});
    }
}
long long dis(int i,int j)
{
    return (F[i].first-B[j].first) * (F[i].first-B[j].first) + (F[i].second-B[j].second)*(F[i].second-B[j].second);
}
long long dp[2003][2003];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> fx >> fy >> bx >> by;
    cin >> f >> b;
    init();
    for(int i=1;i<=n;i++) dp[i][0]=dis(i,0)+dp[i-1][0];
    for(int i=1;i<=m;i++) dp[0][i] = dis(0,i)+dp[0][i-1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] =min( min( dp[i-1][j] , dp[i][j-1] ) , dp[i-1][j-1] ) +dis(i,j);
        }
    }
    cout << dp[n][m];
    return 0;
}
