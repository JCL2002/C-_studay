#include<stdio.h>
int main(){
	int juzhen[256][20],mark=0;
	int i,j;
	scanf("%d %d",&i,&j); //�������У��и���i
	for(int h=0;h<i;h++){
		for(int l=0;l<j;l++){
			scanf("%d",&juzhen[h][l]);//������ֵ 
		}
	}
	//��������
	for(int h=1;h<i-1;h++)//h�����i-1�� 
	{
		for(int l=1;l<j-1;l++)//l�����j-1�� 
		{
			if (juzhen[h][l]>juzhen[h-1][l]&&juzhen[h][l]>juzhen[h][l-1]&&juzhen[h][l]>juzhen[h][l+1]&&juzhen[h][l]>juzhen[h+1][l])//�ĸ�Ը��һ������ 
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
