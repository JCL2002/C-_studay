#include<iostream>
#include<queue>
using namespace std;
int n,m,t;

char Map[2][12][12];

struct lo{
	int x;
	int y;
	int k;//k代表层数
};
queue<lo>Q;
queue<lo>cache;

void bfs(){
	lo  in,out;
	int depth=0;
	in.k=0;in.x=1;in.y=1;
	Q.push(in);
	while(!Q.empty()){
		depth++;
		if(depth>t) break;
		while(!Q.empty()){
			out=Q.front();Q.pop();
			if(Map[out.k][out.x-1][out.y]=='P'){
				cout <<"YES";
				return;
			}
			if(Map[out.k][out.x-1][out.y]=='.'){
				in.k=out.k;in.x=out.x-1;in.y=out.y;
				cache.push(in);
				Map[in.k][in.x][in.y]='*';//走过的路不再走
			}
			if(Map[out.k][out.x-1][out.y]=='#'){//有传送门
				if(out.k&&Map[0][out.x-1][out.y]!='*'&&Map[0][out.x-1][out.y]!='#'){
					in.k=0;in.x=out.x-1;in.y=out.y;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
				else if(out.k==0&&Map[1][out.x-1][out.y]!='*'&&Map[1][out.x-1][out.y]!='#'){
					in.k=1;in.x=out.x-1;in.y=out.y;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
			}
			
			if(Map[out.k][out.x][out.y-1]=='P'){
				cout <<"YES";
				return;
			}
			if(Map[out.k][out.x][out.y-1]=='.'){
				in.k=out.k;in.x=out.x;in.y=out.y-1;
				cache.push(in);
				Map[in.k][in.x][in.y]='*';//走过的路不再走
			}
			if(Map[out.k][out.x][out.y-1]=='#'){
				if(out.k&&Map[0][out.x][out.y-1]!='*'&&Map[0][out.x][out.y-1]!='#'){
					in.k=0;in.x=out.x;in.y=out.y-1;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
				else if(out.k==0&&Map[1][out.x][out.y-1]!='*'&&Map[1][out.x][out.y-1]!='#'){
					in.k=1;in.x=out.x;in.y=out.y-1;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
			}
			
			if(Map[out.k][out.x+1][out.y]=='P'){
				cout <<"YES";
				return ;
			}
			if(Map[out.k][out.x+1][out.y]=='.'){
				in.k=out.k;in.x=out.x+1;in.y=out.y;
				cache.push(in);
				Map[in.k][in.x][in.y]='*';
			}
			if(Map[out.k][out.x+1][out.y]=='#'){
				if(out.k&&Map[0][out.x+1][out.y]!='*'&&Map[0][out.x+1][out.y]!='#'){
					in.k=0;in.x=out.x+1;in.y=out.y;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
				else if(out.k==0&&Map[1][out.x+1][out.y]!='*'&&Map[1][out.x+1][out.y]!='#'){
					in.k=1;in.x=out.x+1;in.y=out.y;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
			}
			
			if(Map[out.k][out.x][out.y+1]=='P'){
				cout <<"YES";
				return ;
			}
			if(Map[out.k][out.x][out.y+1]=='.'){
				in.k=out.k;in.x=out.x;in.y=out.y+1;
				cache.push(in);
				Map[in.k][in.x][in.y]='*';
			}
			if(Map[out.k][out.x][out.y+1]=='#'){
				if(out.k&&Map[0][out.x][out.y+1]!='*'&&Map[0][out.x][out.y+1]!='#'){
					in.k=0;in.x=out.x;in.y=out.y+1;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
				else if(out.k==0&&Map[1][out.x][out.y+1]!='*'&&Map[1][out.x][out.y+1]!='#'){
					in.k=1;in.x=out.x;in.y=out.y+1;
					cache.push(in);
					Map[in.k][in.x][in.y]='*';
				}
			}
		}
		Q=cache;
		while(!cache.empty()) cache.pop();
	}
	cout <<"NO";
}
int main(){
	int j;cin >>j;
	while(j--){
	cin >>n>>m>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >>Map[0][i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >>Map[1][i][j];
		}
	}
	bfs();
	//重置
	while(!cache.empty()) cache.pop();
	while(!Q.empty()) Q.pop(); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			Map[0][i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			Map[1][i][j]=0;
		}
	}
	}
	return 0;
}