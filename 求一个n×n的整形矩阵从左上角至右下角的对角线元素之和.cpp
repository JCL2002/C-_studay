#include<stdio.h>
int main(){
	int a[10][10],n,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		sum+=a[i][i];
	}
	printf("%d\n",sum);
}
