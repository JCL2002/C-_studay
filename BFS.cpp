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
	queue<point>Q;//�����
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
		getchar();//�Իس�
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
		if(start_point.y){//�ж���
			if(T[start_point.x][start_point.y-1].point=='.'&&T[start_point.x][start_point.y-1].step==-1){//��·����
				T[start_point.x][start_point.y+-1].step=step++;
				point_next.x=start_point.x;point_next.y=start_point.y-1;
				Q.push(point_next);
			}
		}
		if(start_point.x){//�ж��Ϸ�
			if(T[start_point.x-1][start_point.y].point=='.'&&T[start_point.x-1][start_point.y].step==-1){//ǰ·����
				T[start_point.x-1][start_point.y].step=step++;
				point_next.x=start_point.x-1;point_next.y=start_point.y;
				Q.push(point_next);
			}
		}
		if(start_point.y!=4){//�ж��ҷ�
			if(T[start_point.x][start_point.y+1].point=='.'&&T[start_point.x][start_point.y+1].step==-1){//��·����
				T[start_point.x][start_point.y+1].step=step++;
				point_next.x=start_point.x;point_next.y=start_point.y+1;
				Q.push(point_next);
			}
		}
		if(start_point.x!=3){//�ж��·�
			if(T[start_point.x+1][start_point.y].point=='.'&&T[start_point.x+1][start_point.y].step==-1){//��·����
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