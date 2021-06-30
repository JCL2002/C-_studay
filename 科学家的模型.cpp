#include<bits/stdc++.h>
using namespace std;
struct loc{
	int x;
	int y;
};
char arr[7][7];
int main(){
	for(int i=0;i<5;i++){
		cin >>arr[i];
	}
	loc ul={0,0},ur={0,0},dl={0,0},dr={0,0};
	bool ex=false;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(arr[i][j]=='1'){
				ex=true;
				ul={i,j};
				break;
			}
		}
		if(ex)break;
	}
	ex=false;
	for(int i=0;i<5;i++){
		for(int j=4;j>0;j--){
			if(arr[i][j]=='1'){
				ex=true;
				ur={i,j};
				break;
			}
		}
		if(ex)break;
	}
	ex=false;
	for(int i=4;i>0;i--){
		for(int j=0;j<5;j++){
			if(arr[i][j]=='1'){
				ex=true;
				dl={i,j};
				break;
			}
		}
		if(ex)break;
	}
	ex=false;
	for(int i=4;i>0;i--){
		for(int j=4;j>0;j--){
			if(arr[i][j]=='1'){
				ex=true;
				dr={i,j};
				break;
			}
		}
		if(ex)break;
	}
	if(arr[(ul.x+dl.x)/2][(ul.y+ur.y)/2]=='0'){
		cout <<"0";
		return 0;
	}
	if(arr[dl.x-1][dl.y]=='0'){
		cout <<"9";
		return 0;
	}
	cout <<"8";
	return 0;
}