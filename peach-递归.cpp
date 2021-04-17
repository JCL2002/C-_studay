#include<stdio.h>
int abc(int n){
	if (n==1) return 1;
	else return 2*(abc(n-1)+1);
}
int main(){
	int n,num;
	scanf("%d",&n);
	num=abc(n);
	printf("%d\n",num);
	return 0;
}
