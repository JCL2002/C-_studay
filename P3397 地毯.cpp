#include<bits/stdc++.h>
using namespace std;
//差分数组
int sum[1002][1002];
int n,m;
int main(){
	cin >>n>>m;
	for(int i=0;i<m;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(int y=y1;y<=y2+1;y++){
			if(y==y1){//起始列
				for(int x=x1;x<=x2;x++){
					sum[x][y]++;
				}
			}
			if(y==y2+1){
				for(int x=x1;x<=x2;x++){
					sum[x][y]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=1;j<=n;j++){
			res+=sum[i][j];
			printf("%d",res);
			if(j!=n){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}