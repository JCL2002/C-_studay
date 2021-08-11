#include<bits/stdc++.h>
using namespace std;
int n,m;
char Map[202][202];
int distance_m[202][202];
int distance_y[202][202];
int way[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct lo{//位置结构体
	int x;
	int y;
};
void init(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			distance_m[i][j]=-1;
			distance_y[i][j]=-1;
			Map[i][j]=0;
		}
	}
}
void bfs_m(){
	lo in,out;
	queue<lo>Q;
	queue<lo>cache;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Map[i][j]=='M'){
				in.x=i;in.y=j;
				Q.push(in);
			}
		}
	}
	int dis=0;
	while(!Q.empty()){
		dis++;
		while(!Q.empty()){
			out=Q.front();Q.pop();
			for(int i=0;i<4;i++){
				if((Map[out.x+way[i][0]][out.y+way[i][1]]=='.'||Map[out.x+way[i][0]][out.y+way[i][1]]=='@')&&distance_m[out.x+way[i][0]][out.y+way[i][1]]==-1){
					in.x=out.x+way[i][0];in.y=out.y+way[i][1];
					cache.push(in);
					distance_m[in.x][in.y]=dis;
				}
			}
		}
		Q=cache;
		while(!cache.empty()) cache.pop();
	}
}

void bfs_y(){
	lo in,out;
	queue<lo>Q;
	queue<lo>cache;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Map[i][j]=='Y'){
				in.x=i;in.y=j;
				Q.push(in);
			}
		}
	}
	int dis=0;
	while(!Q.empty()){
		dis++;
		while(!Q.empty()){
			out=Q.front();Q.pop();
			for(int i=0;i<4;i++){
				if((Map[out.x+way[i][0]][out.y+way[i][1]]=='.'||Map[out.x+way[i][0]][out.y+way[i][1]]=='@')&&distance_y[out.x+way[i][0]][out.y+way[i][1]]==-1){
					in.x=out.x+way[i][0];in.y=out.y+way[i][1];
					cache.push(in);
					distance_y[in.x][in.y]=dis;
				}
			}
		}
		Q=cache;
		while(!cache.empty()) cache.pop();
	}
}

int main(){
	n=201;m=201;
	init();
	while(cin >>n>>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >>Map[i][j];
			}
		}
		bfs_m();
		bfs_y();
		int MIN=100000000;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(Map[i][j]=='@'&&distance_m[i][j]>0&&distance_y[i][j]>0){
					MIN=min(MIN,distance_m[i][j]+distance_y[i][j]);
				}
			}
		}
		cout <<MIN*11<<endl;
		init();
	}
	
	return 0;
}