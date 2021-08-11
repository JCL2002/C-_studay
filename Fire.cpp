#include<bits/stdc++.h>
using namespace std;
char Map[1003][1003];
struct lo{
	int x;
	int y;
};
queue<lo>F;
queue<lo>J;
queue<lo>cache;
int n,m;
void bfs(){
	lo in,out;
	int time=0;
	while(!F.empty()||!J.empty()){
		time++;
		while(!F.empty()){
			out=F.front();F.pop();
			if(Map[out.x-1][out.y]=='.'||Map[out.x-1][out.y]=='J'){
				in.x=out.x-1;in.y=out.y;
				Map[in.x][in.y]='F';
				cache.push(in);
			}
			if(Map[out.x][out.y-1]=='.'||Map[out.x][out.y-1]=='J'){
				in.x=out.x;in.y=out.y-1;
				Map[in.x][in.y]='F';
				cache.push(in);
			}
			if(Map[out.x][out.y+1]=='.'||Map[out.x][out.y+1]=='J'){
				in.x=out.x;in.y=out.y+1;
				Map[in.x][in.y]='F';
				cache.push(in);
			}
			if(Map[out.x+1][out.y]=='.'||Map[out.x+1][out.y]=='J'){
				in.x=out.x+1;in.y=out.y;
				Map[in.x][in.y]='F';
				cache.push(in);
			}
		}
		F=cache;
		while(!cache.empty()) cache.pop();
		while(!J.empty()){
			out=J.front();J.pop();
			if(out.x==n||out.y==m||out.x==1||out.y==1){
				cout <<time<<endl;
				return ;
			}
			if(Map[out.x-1][out.y]=='.'){
				in.x=out.x-1;in.y=out.y;
				Map[in.x][in.y]='J';
				cache.push(in);
			}
			if(Map[out.x][out.y-1]=='.'){
				in.x=out.x;in.y=out.y-1;
				Map[in.x][in.y]='J';
				cache.push(in);
			}
			if(Map[out.x][out.y+1]=='.'){
				in.x=out.x;in.y=out.y+1;
				Map[in.x][in.y]='J';
				cache.push(in);
			}
			if(Map[out.x+1][out.y]=='.'){
				in.x=out.x+1;in.y=out.y;
				Map[in.x][in.y]='J';
				cache.push(in);
			}
		}
		J=cache;
		while(!cache.empty()) cache.pop();
	}
	cout <<"IMPOSSIBLE"<<endl;
	return ;
}

int main(){
	int t;cin >>t;
	while(t--){
		
		cin >>n>>m;
		lo tmp;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >>Map[i][j];
				if(Map[i][j]=='J'){
					tmp.x=i;
					tmp.y=j;
					J.push(tmp);
				}
				if(Map[i][j]=='F'){
					tmp.x=i;
					tmp.y=j;
					F.push(tmp);
				}
			}
		}
		bfs();
		//ÖØÖÃ
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				Map[i][j]=0;
			}
		}
		while(!F.empty()) F.pop();
		while(!J.empty()) J.pop();
		while(!cache.empty()) cache.pop();
	}
	
	return 0;
}