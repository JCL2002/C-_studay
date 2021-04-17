#include<stdio.h>
int main(){
	int a=1,b=1,c,d;
	a=1;
	b=1;
	for (int i=1;i<=20;i++){
		printf("%d %d ",a,b);
		a=a+b;b=a+b;
	}
	printf("\n");
	return 0;
}
