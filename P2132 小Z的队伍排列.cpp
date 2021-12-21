#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,arr[8];
int dp[30][30][30][30][30];
int dfs(int i,int j,int k,int l,int p)
{
	if (i+j+k+l+p==0) return 1;
	int &tp=dp[i][j][k][l][p];
	if (tp) return tp;
	if (i>j) tp+=dfs(i-1,j,k,l,p);
	if (j>k) tp+=dfs(i,j-1,k,l,p);
	if (k>l) tp+=dfs(i,j,k-1,l,p);
	if (l>p) tp+=dfs(i,j,k,l-1,p);
	if (p) tp+=dfs(i,j,k,l,p-1);
	return tp;
}
signed main()
{
    cin.sync_with_stdio(false);
    cin >> k;
    for(int i=0;i<k;i++) cin >> arr[i];
    cout << dfs(arr[0],arr[1],arr[2],arr[3],arr[4]);
    return 0;
}
