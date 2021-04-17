#include<stdio.h>
int main(){
	int n,a[10][10];long long sum=0;
	scanf("%d",&n);
	//矩阵录入 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//先计算所有元素的总和再减去相应元素
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum+=a[i][j];
		}
	}
	//减去最后一行
	for(int j=0;j<n;j++){
		sum-=a[n-1][j];
	}
	//减去最后一列
	for(int i=0;i<n;i++){
		sum-=a[i][n-1];
	}
	//减去副对角线
	for(int i=0;i<n;i++){
		sum-=a[i][n-1-i];
	}
	//加上最后一个元素,左下角元素，右上角，因为它们被减了2次
	sum+=a[n-1][n-1];
	sum+=a[n-1][0];
	sum+=a[0][n-1]; 
	printf("%lld",sum);
}
