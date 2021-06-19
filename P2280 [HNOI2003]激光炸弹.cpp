#include<bits/stdc++.h>
using namespace std;
int sum[5002][5002];
int main(){
	int n,m;
	cin >> n >> m;
	int max_x=0,max_y=0;
	for(int i=0;i<n;i++){
		int x,y;int v;
		scanf("%d %d %d",&x,&y,&v);
		sum[x+1][y+1]=v;
		//找出边界,不做额外的运算
		if(x+1>max_x) max_x=x+1;
		if(y+1>max_y) max_y=y+1;
	}
	//计算前缀和数组
	for(int x=1;x<=max_x;x++){
		for(int y=1;y<=max_y;y++){
			sum[x][y]+=sum[x-1][y]+sum[x][y-1]-sum[x-1][y-1];
		}
	}
	int MAX=0;
	//确定计算边界
	/*
	1:当m<=max_x&&m<=max_y时：从(m,m)到(max_x,max_y);
	2:当m<=max_x&&m>max_y时：从(m,max_y)到(max_x,max_y);
	3:当m>max_x&&m<=max_y时：从(max_x,m)到(max_x,max_y);
	4:当m>max_x&&m>max_y时：从(max_x,max_y)到(max_x,max_y);
	总结规律：从(min(m,max_x),min(m,max_y))到(max_x,max_y);
	从而保证计算的区域全部经过前缀和的计算，而且计算量最小
	*/
	for(int x=min(m,max_x);x<=max_x;x++){
		for(int y=min(m,max_y);y<=max_y;y++){
			//当覆盖的区域不足(m,m)时防止下标越界
			int a,b;
			a=x-m;b=y-m;
			if(a<0) a=0;
			if(b<0) b=0;
			int tmp=sum[x][y]-sum[a][y]-sum[x][b]+sum[a][b];
			if(tmp>MAX) MAX=tmp;
		}
	}
	cout <<MAX;
	return 0;
}