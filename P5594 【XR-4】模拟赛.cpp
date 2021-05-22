#include<bits/stdc++.h>
using namespace std;
int oier[1001][1001];
int inuse[1001];
void init(){
	for(int i=0;i<1001;i++){
		inuse[i]=0;
	}
}
int main(){
	int n,m,k;
	cin >>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int l;scanf("%d",&l);
			oier[i][l]=j;
		}
	}
	for(int i=1;i<=k;i++){
		int differ=0;
		init();//初始化记录数组
		for(int j=1;j<=n;j++){
			if(oier[j][i]&&!inuse[oier[j][i]]){
				differ++;
				inuse[oier[j][i]]++;
			}
		}
		printf("%d ",differ);
	}
	return 0;
}