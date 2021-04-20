#include<bits/stdc++.h>
using namespace std;
struct picture {
	char content;
	int step;
}T[4][5];

struct location{
	int x;int y;
};

int step=1;

void DFS(struct location l){
	struct location l_next;
	if(l.y){//左
		if(T[l.x][l.y-1].content=='.'&&T[l.x][l.y-1].step==-1){
			l_next.x=l.x;l_next.y=l.y-1;
			T[l.x][l.y-1].step=step++;
			DFS(l_next);
		}
	}
	if(l.x){//上
		if(T[l.x-1][l.y].content=='.'&&T[l.x-1][l.y].step==-1){
			l_next.x=l.x-1;l_next.y=l.y;
			T[l.x-1][l.y].step=step++;
			DFS(l_next);
		}
	}
	if(l.y!=4){//右
		if(T[l.x][l.y+1].content=='.'&&T[l.x][l.y+1].step==-1){
			l_next.x=l.x;l_next.y=l.y+1;
			T[l.x][l.y+1].step=step++;
			DFS(l_next);
		}
	}
	if(l.x!=3){//下
		if(T[l.x+1][l.y].content=='.'&&T[l.x+1][l.y].step==-1){
			l_next.x=l.x+1;l_next.y=l.y;
			T[l.x+1][l.y].step=step++;
			DFS(l_next);
		}
	}
	return;
}

int main(){
	int x,y;
	struct location start;
	for(x=0;x<4;x++){
		for(y=0;y<5;y++){
			scanf("%c",&(T[x][y].content));
			T[x][y].step=-1;
			if(T[x][y].content=='@'){
				start.x=x;
				start.y=y;
				T[x][y].step=0;
			}
		}
		getchar();//吃回车
	}
	DFS(start);
	for(x=0;x<4;x++){
		for(y=0;y<5;y++){
			printf("%d\t",T[x][y].step);
		}
		printf("\n");
	}
	return 0;
}