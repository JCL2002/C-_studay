#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int dp[102][102][102];
void Print(int x, int y, int z){
	if (!x || !y || !z) return ;
	if (dp[x][y][z] == dp[x - 1][y][z]) Print(x - 1, y, z) ;
	else if (dp[x][y][z] == dp[x][y - 1][z]) Print(x, y - 1, z) ;
	else if (dp[x][y][z] == dp[x][y][z - 1]) Print(x, y, z - 1) ;
	else if (dp[x][y][z] == dp[x - 1][y - 1][z - 1] + 1) Print(x - 1, y - 1, z - 1), putchar(a[x-1]) ;
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> a >> b >> c;
    for(int i=1; i<=(int)a.length(); i++)
        for(int j=1; j<=(int)b.length(); j++)
            for(int k=1; k<=(int)c.length(); k++)
                if(a[i-1]==b[j-1] &&b[j-1]==c[k-1]) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+1);
                else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
    Print(a.length(),b.length(),c.length());
    return 0;
}
