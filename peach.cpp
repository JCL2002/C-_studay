#include<stdio.h>
int main(){
	int n,num=1;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		num=(num+1)*2;
	}
	printf("%d",num);
	return 0;
}
