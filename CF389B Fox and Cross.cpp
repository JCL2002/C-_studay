#include<bits/stdc++.h>
using namespace std;
bool board[102][102];
int n;
int main(){
	cin >>n;
	scanf("%d",&n);
	char inp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >>inp;
			if(inp=='#')board[i][j]=1;
			else board[i][j]=0;
		}
	}
	for(int i=2;i<n;i++){
		for(int j=2;j<n;j++){
			if(board[i][j]&&board[i-1][j]&&board[i+1][j]&&board[i][j-1]&&board[i][j+1]){
				board[i][j]=board[i-1][j]=board[i+1][j]=board[i][j-1]=board[i][j+1]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(board[i][j]){
				cout <<"NO";
				return 0;
			}
		}
	}
	cout <<"YES";
	return 0;
}