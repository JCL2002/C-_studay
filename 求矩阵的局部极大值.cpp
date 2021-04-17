#include<stdio.h>
int main(){
	int juzhen[256][20],mark=0;
	int i,j;
	scanf("%d %d",&i,&j); //输入行列，行付给i
	for(int h=0;h<i;h++){
		for(int l=0;l<j;l++){
			scanf("%d",&juzhen[h][l]);//传入数值 
		}
	}
	//遍历矩阵
	for(int h=1;h<i-1;h++)//h代表第i-1行 
	{
		for(int l=1;l<j-1;l++)//l代表第j-1列 
		{
			if (juzhen[h][l]>juzhen[h-1][l]&&juzhen[h][l]>juzhen[h][l-1]&&juzhen[h][l]>juzhen[h][l+1]&&juzhen[h][l]>juzhen[h+1][l])//四个愿望一块满足 
			{
				printf("%d %d %d\n",juzhen[h][l],h+1,l+1);
				mark=1;
			}
		}
	}
	if(mark==0){
		printf("None %d %d",i,j);
	}
	return 0;
}
