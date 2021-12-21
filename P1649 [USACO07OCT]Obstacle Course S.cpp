#include<bits/stdc++.h>
using namespace std;
char mp[103][103];
int n,dp[103][103][4];
struct pos
{
    int x,y;
    int dir;//方向
};
pos s,t;
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<4;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++) dp[j][k][i]=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin >> mp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(mp[i][j]=='A') s={i,j};
            else if(mp[i][j]=='B') t={i,j};
    queue<pos> q;
    q.push({s.x,s.y,0});q.push({s.x,s.y,1});q.push({s.x,s.y,2});q.push({s.x,s.y,3});
    dp[s.x][s.y][0]=0;dp[s.x][s.y][1]=0;dp[s.x][s.y][2]=0;dp[s.x][s.y][3]=0;
    //0-3 : 上下左右
    while(!q.empty())
    {
        pos tmp=q.front();q.pop();
        int x=tmp.x,y=tmp.y,d=tmp.dir;
        if(d==0)
        {
            if( mp[x-1][y] != 'x' && x-1 && dp[x-1][y][d] > dp[x][y][d] )
            {
                dp[x-1][y][d] = dp[x][y][d];
                q.push({x-1,y,d});
            }
            if( mp[x][y-1] != 'x' && y-1 && dp[x][y-1][3] > dp[x][y][d] +1 )
            {
                dp[x][y-1][3] = dp[x][y][d] +1;
                q.push({x,y-1,3});
            }
            if(mp[x][y+1] != 'x' && y < n && dp[x][y+1][1] > dp[x][y][d] + 1)
            {
                dp[x][y+1][1] = dp[x][y][d] + 1;
                q.push({x,y+1,1});
            }
        }
        if(d==1)
        {
            if( mp[x][y+1] != 'x' && y < n && dp[x][y+1][d] > dp[x][y][d] )
            {
                dp[x][y+1][d] = dp[x][y][d];
                q.push({x,y+1,d});
            }
            if( mp[x-1][y] != 'x' && x && dp[x-1][y][0] > dp[x][y][d] +1 )
            {
                dp[x-1][y][0] = dp[x][y][d] +1;
                q.push({x-1,y,0});
            }
            if( mp[x+1][y] != 'x' && x < n && dp[x+1][y][2] > dp[x][y][d] + 1)
            {
                dp[x+1][y][2] = dp[x][y][d] + 1;
                q.push({x+1,y,2});
            }
        }
        if(d==2)
        {
            if( mp[x][y+1] != 'x' && y < n && dp[x][y+1][1] > dp[x][y][d] +1 )
            {
                dp[x][y+1][1] = dp[x][y][d] + 1;
                q.push({x,y+1,1});
            }
            if( mp[x][y-1] != 'x' && y && dp[x][y-1][3] > dp[x][y][d] +1 )
            {
                dp[x][y-1][3] = dp[x][y][d] +1;
                q.push({x,y-1,3});
            }
            if( mp[x+1][y] != 'x' && x < n && dp[x+1][y][2] > dp[x][y][d] )
            {
                dp[x+1][y][2] = dp[x][y][d] ;
                q.push({x+1,y,2});
            }
        }
        if(d==3)
        {
            if( mp[x-1][y] != 'x' && x && dp[x-1][y][0] > dp[x][y][d] +1 )
            {
                dp[x-1][y][0] = dp[x][y][d] +1;
                q.push({x-1,y,0});
            }
            if( mp[x][y-1] != 'x' && y && dp[x][y-1][3] > dp[x][y][d]  )
            {
                dp[x][y-1][3] = dp[x][y][d] ;
                q.push({x,y-1,3});
            }
            if( mp[x+1][y] != 'x' &&  x < n && dp[x+1][y][2] > dp[x][y][d] )
            {
                dp[x+1][y][2] = dp[x][y][d] +1;
                q.push({x+1,y,2});
            }
        }
    }
    if(min( min( dp[t.x][t.y][0] , dp[t.x][t.y][1] ) , min( dp[t.x][t.y][2] , dp[t.x][t.y][3] ) ) == 0x3f3f3f3f) cout << -1;
    else cout << min( min( dp[t.x][t.y][0] , dp[t.x][t.y][1] ) , min( dp[t.x][t.y][2] , dp[t.x][t.y][3] ) );
    return 0;
}
