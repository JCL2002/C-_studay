#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x;
	int y;
	int times;
};
vector<Node>lst;
void ist(Node cache){
	for(int i=0;i<(int)lst.size();i++){
		if(lst[i].x==cache.x&&lst[i].y==cache.y){
			lst[i].times++;
			return;
		}
	}
	lst.push_back(cache);//找不到，就加入
}
int main(){
	int x[4][2],y[4][2];
	cin >>x[0][0]>>y[0][0]>>x[0][1]>>y[0][1];
	cin >>x[1][0]>>y[1][0]>>x[1][1]>>y[1][1];
	cin >>x[2][0]>>y[2][0]>>x[2][1]>>y[2][1];
	cin >>x[3][0]>>y[3][0]>>x[3][1]>>y[3][1];
	Node cache;
	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++){
			cache.x=x[i][j];
			cache.y=y[i][j];
			cache.times=1;
			ist(cache);
		}
	}
	bool ok=true;
	if(lst.size()!=4){
		ok=false;
	}
	for(int i=0;i<(int)lst.size();i++){
		if(lst[i].times!=2){
			ok=false;
			break;
		}
	}
	int xdf=false,ydf=false;//判断这四个点在不在一条直线上
	int X=lst[0].x,Y=lst[0].y;
	for(int i=1;i<(int)lst.size();i++){
		if(lst[i].x!=X) xdf=true;
		if(lst[i].y!=Y) ydf=true;
	}
	//判断是否与xy轴平行
	for(int i=0;i<4;i++){
		if(x[i][0]!=x[i][1]&&y[i][0]!=y[i][1]){
			ok=false;
		}
	}
	//看看是不是四条线都平行于y、x轴或者有两条以上平行
	int px=0,py=0;
	for(int i=0;i<4;i++){
		if(x[i][0]==x[i][1]) py++;
		if(y[i][0]==y[i][1]) px++;
	}
	if(px!=2||py!=2){
		ok=false;
	}
	if(ok&&xdf&&ydf){
		cout <<"YES";
	}
	else{
		cout <<"NO";
	}
	return 0;
}