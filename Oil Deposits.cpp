#include<iostream>
using namespace std;
int number;
char Map[103][103];

int m,n;//��,��

void dfs(int x,int y){//x,yΪ�����
	Map[x][y]='*';
	if(Map[x-1][y]=='@') dfs(x-1,y);//��
	if(Map[x][y-1]=='@') dfs(x,y-1);//��
	if(Map[x-1][y-1]=='@') dfs(x-1,y-1);//����
	if(Map[x+1][y]=='@') dfs(x+1,y);//��
	if(Map[x][y+1]=='@') dfs(x,y+1);//��
	if(Map[x+1][y+1]=='@') dfs(x+1,y+1);//����
	if(Map[x+1][y-1]=='@') dfs(x+1,y-1);//����
	if(Map[x-1][y+1]=='@') dfs(x-1,y+1);//����
}

int solve(){
	number=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(Map[i][j]=='@'){
				dfs(i,j);
				number++;
			}
		}
	}
	return number;	
}

int main(){
	while(true){
		cin >>m>>n;
		if(m==0||n==0) break;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin >>Map[i][j];
			}
		}
		cout <<solve()<<endl;
	}
	
	return 0;
}