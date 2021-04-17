#include<stdio.h>
int main(){
	int x[10][10];int i,j;
	//¾ØÕóµÄÊäÈë 
	scanf("%d %d",&i,&j);
	for(int a=0;a<i;a++){
		for(int b=0;b<j;b++){
			scanf("%d",&x[a][b]);
		}
	}
	for(int a=0;a<j;a++){
		for(int b=0;b<i;b++){
			printf("%d ",x[b][a]);
		}
		printf("\n");
	}
	return 0;
}
