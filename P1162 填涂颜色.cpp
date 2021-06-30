#include<bits/stdc++.h>
using namespace std;
int n;
int arr[33][33];
struct Node{
	int x;
	int y;
};
void bfs(int x,int y){
	queue<Node> Q;
	Node t,f;
	t.x=x;t.y=y;
	Q.push(t);
	while(!Q.empty()){
		f=Q.front();
		arr[f.x][f.y]=2;
		if(arr[f.x-1][f.y]==0){
			t.x=f.x-1;
			t.y=f.y;
			Q.push(t);
			arr[f.x-1][f.y]=2;
		}
		if(arr[f.x][f.y-1]==0){
			t.x=f.x;
			t.y=f.y-1;
			Q.push(t);
			arr[f.x][f.y-1]=2;
		}
		if(arr[f.x][f.y+1]==0){
			t.x=f.x;
			t.y=f.y+1;
			Q.push(t);
			arr[f.x][f.y+1]=2;
		}
		if(arr[f.x+1][f.y]==0){
			t.x=f.x+1;
			t.y=f.y;
			Q.push(t);
			arr[f.x+1][f.y]=2;
		}
		Q.pop();
	}
}

int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> arr[i][j];
		}
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]==1){
				if(arr[i][j+1]==0){
//					cout <<i <<"   "<<j+1<<endl;
					bfs(i,j+1);
					flag=true;
				}
				else if(arr[i+1][j+1]==0){
					bfs(i+1,j+1);
					flag=true;
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout <<arr[i][j]<<" ";
		}
		cout <<endl;
	}
	return 0;
}