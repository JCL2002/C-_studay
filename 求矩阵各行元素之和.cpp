#include<stdio.h>
int main(){
	int m,n;int a[6][6];
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		int k=0;
		for(int j=0;j<n;j++){
			k+=a[i][j];
		}
		printf("%d\n",k);
	}
}
