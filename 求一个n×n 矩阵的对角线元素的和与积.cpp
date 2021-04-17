#include<stdio.h>
int main(){
	int a,sum=0,ji=1;
	scanf("%d",&a);int list[a][a];
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			scanf("%d",&list[i][j]);
		}
	}//ÊäÈëÊý×é
	for(int i=0;i<a;i++){
		sum+=list[i][i];
		ji*=list[i][i];
	}
	printf("Sum is: %d\nJi is: %d",sum,ji);
	return 0;
}
