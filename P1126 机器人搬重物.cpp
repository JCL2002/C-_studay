#include<bits/stdc++.h>
using namespace std;
bool Map[52][52];
int dis[52][52];
int N,M;
struct position{
	int x;
	int y;
	char face;
};
bool tst(position current,char face,int dis){//����ܲ����ߵĺ���
	if(face=='W'){//����
		if(current.y-dis>0){
			bool flag=1;
			for(int i=0;i<dis;i++){
				if(Map[current.x][current.y-i]){
					flag=0;
					break;
				}
			}
			if(flag) return true;
		}
		return false;
	}
	if(face=='E'){//����
		if(current.y+dis<M){
			bool flag=1;
			for(int i=0;i<dis;i++){
				if(Map[current.x][current.y+i]){
					flag=0;
					break;
				}
			}
			if(flag) return true;
		}
		return false;
	}
	if(face=='N'){//����
		if(current.x-dis>0){
			bool flag=1;
			for(int i=0;i<dis;i++){
				if(Map[current.x-i][current.y]){
					flag=0;
					break;
				}
			}
			if(flag) return true;
		}
		return false;
	}
	if(face=='S'){//����
		if(current.x+dis<N){
			bool flag=1;
			for(int i=0;i<dis;i++){
				if(Map[current.x+i][current.y]){
					flag=0;
					break;
				}
			}
			if(flag) return true;
		}
		return false;
	}
	return false;
}
void bfs(position start){
	queue <position> Q;
	Q.push(start);
	while(Q.empty()==false){
		position cache=Q.front();Q.pop();//����&����
		position in;
		if(cache.face=='E'){//��
			if(tst(cache,'E',1)&&(dis[cache.x][cache.y]+1<dis[cache.x][cache.y+1]||dis[cache.x][cache.y+1]==-1)){//����Ҫת��
				in.x=cache.x;in.y=cache.y+1;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+1]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'E',2)&&(dis[cache.x][cache.y]+1<dis[cache.x][cache.y+2]||dis[cache.x][cache.y+2]==-1)){
				in.x=cache.x;in.y=cache.y+2;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+2]=dis[cache.x][cache.y]+1;	
			}
			if(tst(cache,'E',3)&&((dis[cache.x][cache.y]+1<dis[cache.x][cache.y+3]||dis[cache.x][cache.y+3]==-1))){
				in.x=cache.x;in.y=cache.y+3;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+3]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'N',1)&&(dis[cache.x][cache.y]+2<dis[cache.x-1][cache.y]||dis[cache.x-1][cache.y]==-1)){
				in.x=cache.x-1;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-1][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'N',2)&&(dis[cache.x][cache.y]+2<dis[cache.x-2][cache.y]||dis[cache.x-2][cache.y]==-1)){
				in.x=cache.x-2;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-2][cache.y]=dis[cache.x][cache.y]+2;
					
			}
			if(tst(cache,'N',3)&&(dis[cache.x][cache.y]+2<dis[cache.x-3][cache.y]||dis[cache.x-3][cache.y]==-1)){
				in.x=cache.x-3;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-3][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'S',1)&&(dis[cache.x][cache.y]+2<dis[cache.x+1][cache.y]||dis[cache.x+1][cache.y]==-1)){
				in.x=cache.x+1;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+1][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'S',2)&&(dis[cache.x][cache.y]+2<dis[cache.x+2][cache.y]||dis[cache.x+1][cache.y]==-1)){
				in.x=cache.x+2;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+2][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'S',3)&&(dis[cache.x][cache.y]+2<dis[cache.x+3][cache.y]||dis[cache.x+3][cache.y]==-1)){
				in.x=cache.x+3;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+3][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'W',1)&&(dis[cache.x][cache.y]+3<dis[cache.x][cache.y-1]||dis[cache.x][cache.y-1]==-1)){
				in.x=cache.x;in.y=cache.y-1;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-1]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'W',2)&&(dis[cache.x][cache.y]+3<dis[cache.x][cache.y-2]||dis[cache.x][cache.y-2]==-1)){
				in.x=cache.x;in.y=cache.y-2;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-2]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'W',3)&&(dis[cache.x][cache.y]+3<dis[cache.x][cache.y-3]||dis[cache.x][cache.y-3]==-1)){
				in.x=cache.x;in.y=cache.y-3;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-3]=dis[cache.x][cache.y]+3;
			}
		}
		if(cache.face=='S'){//����
			if(tst(cache,'S',1)&&(dis[cache.x][cache.y]+1<dis[cache.x+1][cache.y]||dis[cache.x+1][cache.y]==-1)){//����Ҫת��
				in.x=cache.x+1;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+1][cache.y]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'S',2)&&(dis[cache.x][cache.y]+1<dis[cache.x+2][cache.y]||dis[cache.x+2][cache.y]==-1)){
					in.x=cache.x+2;in.y=cache.y;in.face='S';
					Q.push(in);
					dis[cache.x+2][cache.y]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'S',3)&&((dis[cache.x][cache.y]+1<dis[cache.x+3][cache.y]||dis[cache.x+3][cache.y]==-1))){
				in.x=cache.x+3;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+3][cache.y]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'E',1)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y+1]||dis[cache.x][cache.y+1]==-1)){
				in.x=cache.x;in.y=cache.y+1;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+1]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'E',2)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y+2]||dis[cache.x][cache.y+2]==-1)){
					in.x=cache.x;in.y=cache.y+2;in.face='E';
					Q.push(in);
					dis[cache.x][cache.y+2]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'E',3)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y+3]||dis[cache.x][cache.y+3]==-1)){
				in.x=cache.x;in.y=cache.y+3;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+3]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'W',1)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y-1]||dis[cache.x][cache.y-1]==-1)){
				in.x=cache.x;in.y=cache.y-1;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-1]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'W',2)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y-2]||dis[cache.x][cache.y-2]==-1)){
				in.x=cache.x;in.y=cache.y-2;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-2]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'W',3)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y-3]||dis[cache.x][cache.y-3]==-1)){
				in.x=cache.x;in.y=cache.y-3;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-3]=dis[cache.x][cache.y]+2;
			}
			
			if(tst(cache,'N',1)&&(dis[cache.x][cache.y]+3<dis[cache.x-1][cache.y]||dis[cache.x-1][cache.y]==-1)){
				in.x=cache.x-1;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-1][cache.y]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'N',2)&&(dis[cache.x][cache.y]+3<dis[cache.x-2][cache.y]||dis[cache.x-2][cache.y]==-1)){
				in.x=cache.x-2;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-2][cache.y]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'N',3)&&(dis[cache.x][cache.y]+3<dis[cache.x-3][cache.y]||dis[cache.x-3][cache.y]==-1)){
				in.x=cache.x-3;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-3][cache.y]=dis[cache.x][cache.y]+3;
			}
		}
		if(cache.face=='W'){//����
			if(tst(cache,'W',1)&&(dis[cache.x][cache.y]+1<dis[cache.x][cache.y-1]||dis[cache.x][cache.y-1]==-1)){//����Ҫת��
				in.x=cache.x;in.y=cache.y-1;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-1]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'W',2)&&(dis[cache.x][cache.y]+1<dis[cache.x][cache.y-2]||dis[cache.x][cache.y-2]==-1)){
				in.x=cache.x;in.y=cache.y-2;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-2]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'W',3)&&((dis[cache.x][cache.y]+1<dis[cache.x][cache.y-3]||dis[cache.x][cache.y-3]==-1))){
				in.x=cache.x;in.y=cache.y-3;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-3]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'S',1)&&(dis[cache.x][cache.y]+2<dis[cache.x+1][cache.y]||dis[cache.x+1][cache.y]==-1)){
				in.x=cache.x+1;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+1][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'S',2)&&(dis[cache.x][cache.y]+2<dis[cache.x+2][cache.y]||dis[cache.x+2][cache.y]==-1)){
				in.x=cache.x+2;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+2][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'S',3)&&(dis[cache.x][cache.y]+2<dis[cache.x+3][cache.y]||dis[cache.x+3][cache.y]==-1)){
				in.x=cache.x+3;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+3][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'N',1)&&(dis[cache.x][cache.y]+2<dis[cache.x-1][cache.y]||dis[cache.x-1][cache.y]==-1)){
				in.x=cache.x-1;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-1][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'N',2)&&(dis[cache.x][cache.y]+2<dis[cache.x-2][cache.y]||dis[cache.x-2][cache.y]==-1)){
				in.x=cache.x-2;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-2][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'N',3)&&(dis[cache.x][cache.y]+2<dis[cache.x-3][cache.y]||dis[cache.x-3][cache.y]==-1)){
				in.x=cache.x-3;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-3][cache.y]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'E',1)&&(dis[cache.x][cache.y]+3<dis[cache.x][cache.y+1]||dis[cache.x][cache.y+1]==-1)){
				in.x=cache.x;in.y=cache.y+1;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+1]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'E',2)&&(dis[cache.x][cache.y]+3<dis[cache.x][cache.y+2]||dis[cache.x][cache.y+2]==-1)){
				in.x=cache.x;in.y=cache.y+2;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+2]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'E',3)&&(dis[cache.x][cache.y]+3<dis[cache.x][cache.y+3]||dis[cache.x][cache.y+3]==-1)){
				in.x=cache.x;in.y=cache.y+3;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+3]=dis[cache.x][cache.y]+3;
			}
		}
		if(cache.face=='N'){//��
			if(tst(cache,'N',1)&&(dis[cache.x][cache.y]+1<dis[cache.x-1][cache.y]||dis[cache.x-1][cache.y]==-1)){//����Ҫת��
				in.x=cache.x-1;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-1][cache.y]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'N',2)&&(dis[cache.x][cache.y]+1<dis[cache.x-2][cache.y]||dis[cache.x-2][cache.y]==-1)){
				in.x=cache.x-2;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-2][cache.y]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'N',3)&&((dis[cache.x][cache.y]+1<dis[cache.x-3][cache.y]||dis[cache.x-3][cache.y]==-1))){
				in.x=cache.x-3;in.y=cache.y;in.face='N';
				Q.push(in);
				dis[cache.x-3][cache.y]=dis[cache.x][cache.y]+1;
			}
			if(tst(cache,'W',1)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y-1]||dis[cache.x][cache.y-1]==-1)){
				in.x=cache.x;in.y=cache.y-1;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-1]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'W',2)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y-2]||dis[cache.x][cache.y-2]==-1)){
				in.x=cache.x;in.y=cache.y-2;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-2]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'W',3)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y-3]||dis[cache.x][cache.y-3]==-1)){
				in.x=cache.x;in.y=cache.y-3;in.face='W';
				Q.push(in);
				dis[cache.x][cache.y-3]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'E',1)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y+1]||dis[cache.x][cache.y+1]==-1)){
				in.x=cache.x;in.y=cache.y+1;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+1]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'E',2)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y+2]||dis[cache.x][cache.y+2]==-1)){
				in.x=cache.x;in.y=cache.y+2;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+2]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'E',3)&&(dis[cache.x][cache.y]+2<dis[cache.x][cache.y+3]||dis[cache.x][cache.y+3]==-1)){
				in.x=cache.x;in.y=cache.y+3;in.face='E';
				Q.push(in);
				dis[cache.x][cache.y+3]=dis[cache.x][cache.y]+2;
			}
			if(tst(cache,'S',1)&&(dis[cache.x][cache.y]+3<dis[cache.x+1][cache.y]||dis[cache.x+1][cache.y]==-1)){
				in.x=cache.x+1;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+1][cache.y]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'S',2)&&(dis[cache.x][cache.y]+3<dis[cache.x+2][cache.y]||dis[cache.x+1][cache.y]==-1)){
				in.x=cache.x+2;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+2][cache.y]=dis[cache.x][cache.y]+3;
			}
			if(tst(cache,'S',3)&&(dis[cache.x][cache.y]+3<dis[cache.x+3][cache.y]||dis[cache.x+3][cache.y]==-1)){
				in.x=cache.x+3;in.y=cache.y;in.face='S';
				Q.push(in);
				dis[cache.x+3][cache.y]=dis[cache.x][cache.y]+3;
			}
		}
	}
}
position start,target;
int main(){
	for(int i=0;i<52;i++){
		for(int j=0;j<52;j++){
			dis[i][j]=-1;//�����ʼ��Ϊ����Զ
		}
	}
	cin >>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			bool tmp;cin >>tmp;
			if(tmp){
				Map[i-1][j-1]=true;Map[i-1][j]=true;
				Map[i][j-1]=true;Map[i][j]=true;
			}
		}
	}
	cin >>start.x>>start.y>>target.x>>target.y>>start.face;
	dis[start.x][start.y]=0;
	bfs(start);
	cout <<dis[target.x][target.y]<<endl;
	return 0;
}