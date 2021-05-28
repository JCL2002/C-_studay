#include<bits/stdc++.h>
using namespace std;
struct position{
	int x;
	int y;
};
struct M{
	bool search;
	int val;
};
M matrix[1001][1001];
int n,m;
void Init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			matrix[i][j].search=true;
		}
	}
}
bool dfs(int val,position P){
	//深度优先搜索，当前val能满足条件就返回true
	if(P.x==n){
		return true;
	}
	queue<position>line;
	//下一步DFS对象
	position Q;
	if(matrix[P.x+1][P.y].search&&matrix[P.x+1][P.y].val<=val){
		Q.x=P.x+1;Q.y=P.y;
		line.push(Q);
	}
	if(matrix[P.x-1][P.y].search&&matrix[P.x-1][P.y].val<=val){
		Q.x=P.x-1;Q.y=P.y;
		line.push(Q);
	}
	if(matrix[P.x][P.y+1].search&&matrix[P.x][P.y+1].val<=val){
		Q.x=P.x;Q.y=P.y+1;
		line.push(Q);
	}
	if(matrix[P.x][P.y-1].search&&matrix[P.x][P.y-1].val<=val){
		Q.x=P.x;Q.y=P.y-1;
		line.push(Q);
	}
	//开始DFS
	while(!line.empty()){
		Q=line.front();
		matrix[Q.x][Q.y].search=false;
		if(!dfs(val,Q)){
			line.pop();
			continue;
		}
		else{
			return true;
		}
	}
	return false;
}
int main(){
	cin >>n>>m;
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&matrix[i][j].val);
			if(matrix[i][j].val>max){
				max=matrix[i][j].val;
			}
			matrix[i][j].search=true;
		}
	}
	int min=1;
	position init;
	init.x=1;init.y=1;
	while(true){
		Init();
		int mid=(min+max)/2;
		if(min==max){
			break;
		}
		if(dfs(mid,init)){
			if(dfs(mid-1,init)){
				max=mid-1;
				continue;
			}
			else{
				max=mid;
			}
		}
		else{
			min=mid+1;
		}
	}
	cout <<min;
	return 0;
}