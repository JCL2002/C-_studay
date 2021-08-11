#include<bits/stdc++.h>
using namespace std;
char sudo[11][11];
int main(){
	int t;cin >>t;
	while(t--){
		
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			cin >>sudo[i][j];
		}
	}
	sudo[1][1]='0'+(sudo[1][1]-'0')%9+1;
	sudo[2][4]='0'+(sudo[2][4]-'0')%9+1;
	sudo[3][7]='0'+(sudo[3][7]-'0')%9+1;
	sudo[4][2]='0'+(sudo[4][2]-'0')%9+1;
	sudo[5][5]='0'+(sudo[5][5]-'0')%9+1;
	sudo[6][8]='0'+(sudo[6][8]-'0')%9+1;
	sudo[7][3]='0'+(sudo[7][3]-'0')%9+1;
	sudo[8][6]='0'+(sudo[8][6]-'0')%9+1;
	sudo[9][9]='0'+(sudo[9][9]-'0')%9+1;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout <<sudo[i][j];
		}
		cout <<endl;
	}
}
	return 0;
}