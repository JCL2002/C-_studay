#include<bits/stdc++.h>
using namespace std;
int n,m;//如题干所示
int ans[100005];
vector<int>G[100005];
void dfs(int n,int i){
	if(ans[i]) return ;
	ans[i]=n;
	for(int j=0;j<(int)G[i].size();j++){
		dfs(n,G[i][j]);
	}
}
int main(){
	cin >>n>>m;
	for(int i=1;i<=m;i++){
		int f,t;
		scanf("%d %d",&f,&t);
		G[t].push_back(f);
	}
	for(int i=n;i>0;i--){
		dfs(i,i);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}