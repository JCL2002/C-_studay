#include<bits/stdc++.h>
using namespace std;
int X,Y,T;
struct M{
	char c;
	int ckl;
};
M Map[202][202];
struct lo{
	int x;
	int y;
	int ckl;
	int distance;
};

void bfs(int x,int y){
	queue<lo>Q;
	lo in,out;
	in.ckl=Map[x][y].ckl;
	in.distance=0;
	in.x=x;in.y=y;
	Q.push(in);
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			if(Map[i][j].c=='+'){
				x=i;y=j;
			}
		}
	}
	while(!Q.empty()){
		out = Q.front();Q.pop();
		if(out.x==x&&out.y==y){
			cout <<out.distance<<endl<<endl;
			exit(0);
		}
		if((Map[out.x][out.y+1].c=='*'||Map[out.x][out.y+1].c=='+')&&out.ckl>Map[out.x][out.y+1].ckl){
			in.x=out.x;in.y=out.y+1;
			in.ckl=out.ckl;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][in.y].ckl=in.ckl;
		}
		if((Map[out.x+1][out.y].c=='*'||Map[out.x+1][out.y].c=='+')&&out.ckl>Map[out.x+1][out.y].ckl){
			in.x=out.x+1;in.y=out.y;
			in.ckl=out.ckl;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][in.y].ckl=in.ckl;
		}
		if((Map[out.x][out.y-1].c=='*'||Map[out.x][out.y-1].c=='+')&&out.ckl>Map[out.x][out.y-1].ckl){
			
			in.x=out.x;in.y=out.y-1;
			in.ckl=out.ckl;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][in.y].ckl=in.ckl;
		}
		if((Map[out.x-1][out.y].c=='*'||Map[out.x-1][out.y].c=='+')&&out.ckl>Map[out.x-1][out.y].ckl){
			in.x=out.x-1;in.y=out.y;
			in.ckl=out.ckl;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][in.y].ckl=in.ckl;
		}
		
		if(Map[out.x][out.y+1].c=='#'&&out.ckl>Map[out.x][out.y+1].ckl){
			in.x=out.x;in.y=out.y+1;
			in.ckl=out.ckl-1;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][out.y].ckl=out.ckl;
		}
		if(Map[out.x+1][out.y].c=='#'&&out.ckl>Map[out.x+1][out.y].ckl&&out.ckl>0){
			in.x=out.x+1;in.y=out.y;
			in.ckl=out.ckl-1;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][out.y].ckl=out.ckl;
		}
		if(Map[out.x-1][out.y].c=='#'&&out.ckl>Map[out.x-1][out.y].ckl&&out.ckl>0){
			in.x=out.x-1;in.y=out.y;
			in.ckl=out.ckl-1;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][out.y].ckl=out.ckl;
		}
		if(Map[out.x][out.y-1].c=='#'&&out.ckl>Map[out.x][out.y-1].ckl&&out.ckl>0){
			in.x=out.x;in.y=out.y-1;
			in.ckl=out.ckl-1;
			in.distance=out.distance+1;
			Q.push(in);
			Map[in.x][out.y].ckl=out.ckl;
		}
	}
}
int main(){
	cin >>X>>Y>>T;
	int x=0,y=0;
	for(int i=1;i<=X;i++){//地图输入
		for(int j=1;j<=Y;j++){
			cin >>Map[i][j].c;
			Map[i][j].ckl=-1;//查克拉的初始值为-1
			if(Map[i][j].c=='@'){
				Map[i][j].ckl=T;
				x=i;y=j;
			}
		}
	}
	bfs(x,y);
	cout <<-1;
	return 0;
}