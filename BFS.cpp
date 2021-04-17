#include<bits/stdc++.h>
using namespace std;
struct point {
	int x;int y;
};

struct pict{
	char point;
	int step;
};
struct pict T[4][5];

int main(){
	queue<point>Q;//点队列
	int x,y,step=1;
	struct point start_point,point_next;
	for(x=0;x<4;x++){
		for(y=0;y<5;y++){
			scanf("%c",&(T[x][y].point));
			T[x][y].step=-1;
			if(T[x][y].point=='@'){
				start_point.x=x;
				start_point.y=y;
				T[x][y].step=0;
			}
		}
		getchar();//吃回车
	}
	Q.push(start_point);
	while(1){
		if(Q.empty()){
			break;
		}
		else{
			start_point=Q.front();
			Q.pop();
		}
		if(start_point.y){//判断左方
			if(T[start_point.x][start_point.y-1].point=='.'&&T[start_point.x][start_point.y-1].step==-1){//右路可行
				T[start_point.x][start_point.y+-1].step=step++;
				point_next.x=start_point.x;point_next.y=start_point.y-1;
				Q.push(point_next);
			}
		}
		if(start_point.x){//判断上方
			if(T[start_point.x-1][start_point.y].point=='.'&&T[start_point.x-1][start_point.y].step==-1){//前路可行
				T[start_point.x-1][start_point.y].step=step++;
				point_next.x=start_point.x-1;point_next.y=start_point.y;
				Q.push(point_next);
			}
		}
		if(start_point.y!=4){//判断右方
			if(T[start_point.x][start_point.y+1].point=='.'&&T[start_point.x][start_point.y+1].step==-1){//右路可行
				T[start_point.x][start_point.y+1].step=step++;
				point_next.x=start_point.x;point_next.y=start_point.y+1;
				Q.push(point_next);
			}
		}
		if(start_point.x!=3){//判断下方
			if(T[start_point.x+1][start_point.y].point=='.'&&T[start_point.x+1][start_point.y].step==-1){//右路可行
				T[start_point.x+1][start_point.y].step=step++;
				point_next.x=start_point.x+1;point_next.y=start_point.y;
				Q.push(point_next);
			}
		}
	}
	for(x=0;x<4;x++){
		for(y=0;y<5;y++){
			printf("%d\t",T[x][y].step);
		}
		printf("\n");
	}
	return 0;
}