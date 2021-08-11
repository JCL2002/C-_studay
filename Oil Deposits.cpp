#include<iostream>
using namespace std;
int number;
char Map[103][103];

int m,n;//行,列

void dfs(int x,int y){//x,y为切入点
	Map[x][y]='*';
	if(Map[x-1][y]=='@') dfs(x-1,y);//上
	if(Map[x][y-1]=='@') dfs(x,y-1);//左
	if(Map[x-1][y-1]=='@') dfs(x-1,y-1);//左上
	if(Map[x+1][y]=='@') dfs(x+1,y);//下
	if(Map[x][y+1]=='@') dfs(x,y+1);//右
	if(Map[x+1][y+1]=='@') dfs(x+1,y+1);//右下
	if(Map[x+1][y-1]=='@') dfs(x+1,y-1);//左下
	if(Map[x-1][y+1]=='@') dfs(x-1,y+1);//右上
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