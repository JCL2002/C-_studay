#include<stdio.h>
int main(){
	int a[6][6];int n;int H_MAX[6],L_MIN[6];
	scanf("%d",&n);
	//矩阵录入 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int max,min;
	//求行最大的最大并把其存在H_MAX中
	for(int i=0;i<n;i++){
		max=a[i][0];
		for(int j=1;j<n;j++){
			if(max<a[i][j]) max=a[i][j];
		}
		H_MAX[i]=max;
	}
	//求出每列的最小值并把其存在H_MIN中
	for(int j=0;j<n;j++){
		min=a[0][j];
		for(int i=1;i<n;i++){
			if(min>a[i][j]) min=a[i][j];
		}
		L_MIN[j]=min;
	}
	//遍历所有数据，当前数据与当前行、列的最大/小值都相等时输出这个值
	int mark=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==H_MAX[i]&&a[i][j]==L_MIN[j]) {
				printf("%d %d",i,j);
				mark=1;
			}
		}
	}
	if(mark==0){
		printf("NONE");
	}
	return 0;
} 
