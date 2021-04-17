#include<stdio.h>
void  arrayShiftRight(int a[ ],int n,int m){
	m=m%n;//解决当M≥N的问题
	//移动数组
	int b[256];
	for(int i=0;i<n;i++){
		if(i<(n-m)) {
			b[i+m]=a[i];
		}
		else {
			b[i-n+m]=a[i];
		}
	}
	for(int i=0;i<n;i++){
		a[i]=b[i];
	}
}
int main(){
	int i,n,m;
        scanf("%d%d",&n,&m);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
        arrayShiftRight(arr,n,m);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
