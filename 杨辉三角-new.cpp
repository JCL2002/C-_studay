#include<stdio.h>
long long C(int x,int y){
	long long fenzi=1,fenmu=1;
	if (y==0){
		return 1;
	}
	if(x==0){
		printf("Error!");
	}
	//计算分子 
	for(int i=x;i>(x-y);i--){
		fenzi*=i;
	}
	//计算分母
	for(int i=y;i>0;i--){
		fenmu*=i;
	}
	return (fenzi/fenmu);
}
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		if (i==0){
			printf("1");
		}
		else{
			for(int j=0;j<=i;j++){
				printf("%lld ",C(i,j));
			}
		}
		printf("\n");
	}
	return 0;
}
