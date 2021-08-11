#include<bits/stdc++.h>
using namespace std;
//采用邻接表存图
int n,m;
vector<int>G[100005];
bool vis[100005];
void DFS(int out){
	if(vis[out])return;
	vis[out]=1;
	printf("%d ",out);
	for(int j=0;j<(int)G[out].size();j++){
		DFS(G[out][j]);
	}
}
int main(){
	cin >>n>>m;
	//n是博客数量；m是链接的数量
	for(int i=1;i<=m;i++){//数据的录入
		int from,to;
		scanf("%d %d",&from,&to);
		G[from].push_back(to);
	}
	for(int i=1;i<=n;i++){//对邻接表排序
		sort(G[i].begin(),G[i].end());
	}
	//DFS部分
	DFS(1);
	cout <<endl;
	//BFS部分
	//初始化
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	queue<int>zero;//入度为0的节点
	zero.push(1);//以1为起点
	//开始BFS
	while(!zero.empty()){//BFS
		int out=zero.front();zero.pop();
		vis[out]=1;
		printf("%d ",out);
		//检查所有入度为0的点
		for(int i=0;i<(int)G[out].size();i++){
			if(vis[G[out][i]]==false){
				vis[G[out][i]]=true;
				zero.push(G[out][i]);
			}
		}
	}
	return 0;
}