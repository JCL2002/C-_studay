#include<bits/stdc++.h>
using namespace std;
struct MAP{
	int color;
	int cost;
};
MAP arr[102][102];
struct step{
	int x;
	int y;
	int cost;
	int color;
	bool magic;//��ǰ���Ƿ�ʹ����ħ��
};
int m,n;
void bfs(){
	queue<step>Q;
	step in;
	step out;
	in.color=arr[1][1].color;
	in.magic=false;
	in.x=1;
	in.y=1;
	in.cost=0;
	arr[1][1].cost=0;
	Q.push(in);
	while(!Q.empty()){
		out=Q.front();
		if(out.magic){//ʹ����ħ��
			if(out.x-1>0){//��Խ��
				if(out.color==arr[out.x-1][out.y].color){//ͬɫ
					if(out.cost<arr[out.x-1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x-1][out.y].cost=out.cost;
						in.x=out.x-1;in.y=out.y;in.color=out.color;in.magic=false;
						Q.push(in);
					}
				}
				else if(arr[out.x-1][out.y].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x-1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x-1][out.y].cost=out.cost+1;
						in.x=out.x-1;in.y=out.y;in.color=arr[out.x-1][out.y].color;in.magic=false;
						Q.push(in);
					}
				}
			}
			if(out.y-1>0){//��Խ��
				if(out.color==arr[out.x][out.y-1].color){//ͬɫ
					if(out.cost<arr[out.x][out.y-1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y-1].cost=out.cost;
						in.x=out.x;in.y=out.y-1;in.color=out.color;in.magic=false;
						Q.push(in);
					}
				}
				else if(arr[out.x][out.y-1].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x][out.y-1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y-1].cost=out.cost+1;
						in.x=out.x;in.y=out.y-1;in.color=arr[out.x][out.y-1].color;in.magic=false;
						Q.push(in);
					}
				}
			}
			if(out.x+1<=m){//��Խ��
				if(out.color==arr[out.x+1][out.y].color){//ͬɫ
					if(out.cost<arr[out.x+1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x+1][out.y].cost=out.cost;
						in.x=out.x+1;in.y=out.y;in.color=out.color;in.magic=false;
						Q.push(in);
					}
				}
				else if(arr[out.x+1][out.y].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x+1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x+1][out.y].cost=out.cost+1;
						in.x=out.x+1;in.y=out.y;in.color=arr[out.x+1][out.y].color;in.magic=false;
						Q.push(in);
					}
				}
			}
			if(out.y+1<=m){//��Խ��
				if(out.color==arr[out.x][out.y+1].color){//ͬɫ
					if(out.cost<arr[out.x][out.y+1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y+1].cost=out.cost;
						in.x=out.x;in.y=out.y+1;in.color=out.color;in.magic=false;
						Q.push(in);
						
					}
				}
				else if(arr[out.x][out.y+1].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x][out.y+1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y+1].cost=out.cost+1;
						in.x=out.x;in.y=out.y+1;in.color=arr[out.x][out.y+1].color;in.magic=false;
						Q.push(in);
					}
				}
			}
		}
		else{//û��ʹ��ħ��
			if(out.x-1>0){//��Խ��
				if(out.color==arr[out.x-1][out.y].color){//��ɫ
					if(out.cost<arr[out.x-1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x-1][out.y].cost=out.cost;
						in.x=out.x-1;in.y=out.y;in.color=out.color;in.magic=false;
						Q.push(in);
					}
				}
				else if(arr[out.x-1][out.y].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x-1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x-1][out.y].cost=out.cost+1;
						in.x=out.x-1;in.y=out.y;in.color=arr[out.x-1][out.y].color;in.magic=false;
						Q.push(in);
					}
				}
				else{//ʹ��ħ��
					if(out.cost+2<arr[out.x-1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x-1][out.y].cost=out.cost+2;
						in.x=out.x-1;in.y=out.y;in.color=out.color;in.magic=true;
						Q.push(in);
					}
				}
			}
			if(out.y-1>0){//��Խ��
				if(out.color==arr[out.x][out.y-1].color){//ͬɫ
					if(out.cost<arr[out.x][out.y-1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y-1].cost=out.cost;
						in.x=out.x;in.y=out.y-1;in.color=out.color;in.magic=false;
						Q.push(in);
					}
				}
				else if(arr[out.x][out.y-1].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x][out.y-1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y-1].cost=out.cost+1;
						in.x=out.x;in.y=out.y-1;in.color=arr[out.x][out.y-1].color;in.magic=false;
						Q.push(in);
					}
				}
				else{
					if(out.cost+2<arr[out.x][out.y-1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y-1].cost=out.cost+2;
						in.x=out.x;in.y=out.y-1;in.color=out.color;in.magic=true;
						Q.push(in);
					}
				}
			}
			if(out.x+1<=m){//��Խ��
				if(out.color==arr[out.x+1][out.y].color){//ͬɫ
					if(out.cost<arr[out.x+1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x+1][out.y].cost=out.cost;
						in.x=out.x+1;in.y=out.y;in.color=out.color;in.magic=false;
						Q.push(in);
					}
				}
				else if(arr[out.x+1][out.y].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x+1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x+1][out.y].cost=out.cost+1;
						in.x=out.x+1;in.y=out.y;in.color=arr[out.x+1][out.y].color;in.magic=false;
						Q.push(in);
					}
				}
				else{
					if(out.cost+2<arr[out.x+1][out.y].cost){//�б�Ҫ��
						in.cost=arr[out.x+1][out.y].cost=out.cost+2;
						in.x=out.x+1;in.y=out.y;in.color=out.color;in.magic=true;
						Q.push(in);
					}
				}
			}
			if(out.y+1<=m){//��Խ��
				if(out.color==arr[out.x][out.y+1].color){//ͬɫ
					if(out.cost<arr[out.x][out.y+1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y+1].cost=out.cost;
						in.x=out.x;in.y=out.y+1;in.color=out.color;in.magic=false;
						Q.push(in);
					}
				}
				else if(arr[out.x][out.y+1].color!=-1){//������ɫ
					if(out.cost+1<arr[out.x][out.y+1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y+1].cost=out.cost+1;
						in.x=out.x;in.y=out.y+1;in.color=arr[out.x][out.y+1].color;in.magic=false;
						Q.push(in);
					}
				}
				else{
					if(out.cost+2<arr[out.x][out.y+1].cost){//�б�Ҫ��
						in.cost=arr[out.x][out.y+1].cost=out.cost+2;
						in.x=out.x;in.y=out.y+1;in.color=out.color;in.magic=true;
						Q.push(in);
					}
				}
			}
		}
		Q.pop();
	}
}
int main(){
	cin >>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			arr[i][j].color=-1;
			arr[i][j].cost=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);scanf("%d",&arr[x][y].color);
	}
	bfs();
	if(arr[m][m].cost==1e9){
		cout <<-1;
	}
	else{
		cout <<arr[m][m].cost;
	}
	return 0;
}