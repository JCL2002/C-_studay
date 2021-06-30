#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[402][402];
int len;
int step;
struct point{
	int x;
	int y;
};
void bfs(int x,int y){
	queue<point>Q;//bfs����
	arr[x][y]=0;
	point in,out;
	in.x=x;in.y=y;
	Q.push(in);
	step=1;//ÿһ��bfsԪ�ص�����
	while(!Q.empty()){
		out=Q.front();
		arr[out.x][out.y]=len;
		if(out.x-1>0&&out.y-2>0&&arr[out.x-1][out.y-2]==-1){
			in.x=out.x-1;
			in.y=out.y-2;
			arr[out.x-1][out.y-2]=len+1;
			Q.push(in);
		}
		if(out.x+1<=n&&out.y-2>0&&arr[out.x+1][out.y-2]==-1){
			
			in.x=out.x+1;
			in.y=out.y-2;
			arr[out.x+1][out.y-2]=len+1;
			Q.push(in);
		}
		if(out.x-2>0&&out.y-1>0&&arr[out.x-2][out.y-1]==-1){
			in.x=out.x-2;
			in.y=out.y-1;
			arr[out.x-2][out.y-1]=len+1;
			Q.push(in);
		}
		if(out.x+2<=n&&out.y-1>0&&arr[out.x+2][out.y-1]==-1){
			in.x=out.x+2;
			in.y=out.y-1;
			arr[out.x+2][out.y-1]=len+1;
			Q.push(in);
		}
		if(out.x-2>0&&out.y+1<=m&&arr[out.x-2][out.y+1]==-1){
			in.x=out.x-2;
			in.y=out.y+1;
			arr[out.x-2][out.y+1]=len+1;
			Q.push(in);
		}
		if(out.x+2<=n&&out.y+1<=m&&arr[out.x+2][out.y+1]==-1){
			in.x=out.x+2;
			in.y=out.y+1;
			arr[out.x+2][out.y+1]=len+1;
			Q.push(in);
		}
		if(out.x-1>0&&out.y+2<=m&&arr[out.x-1][out.y+2]==-1){
			in.x=out.x-1;
			in.y=out.y+2;
			arr[out.x-1][out.y+2]=len+1;
			Q.push(in);
		}
		if(out.x+1<=n&&out.y+2<=m&&arr[out.x+1][out.y+2]==-1){
			in.x=out.x+1;
			in.y=out.y+2;
			arr[out.x+1][out.y+2]=len+1;
			Q.push(in);
		}
		Q.pop();
		step--;
		if(step==0){//��ǰ��������
			len++;//·������+1
			step=Q.size();//��ȡ��һ�����
		}
	}
}
int main(){
	int x,y;
	cin >>n >>m>>x>>y;//n��m��
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]=-1;
		}
	}
	bfs(x,y);
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cout<<left<<setw(5)<<arr[i][j];//�����о� 
        cout<<endl;
    }
	return 0;
}