#include<stdio.h>
int main(){
	int target_x,target_b,horse_x,horse_y;
	scanf("%d %d %d %d",target_x,target_b,horse_x,horse_y);
	int a[20][20];
	//a��ʼ��Ϊ1
	for(int i=0;i<20;i++){
		for(int j;j<20;j++){
			a[i][j]=1;
		}
	}
	//��������ܲȵ���λ����Ϊ0
	a[horse_x][horse_y]=0;
	if((horse_x-1)>0&&(gorse_y-2)>0){
		a[horse_x-1][gorse_y-2]=0;
	}
	if(())
	long long count;
	
	return 0;
}
//��������� 
long long C(int x,int y){
	long long fenzi=1,fenmu=1;
	if (y==0){
		return 1;
	}
	if(x==0){
		printf("Error!");
	}
	//������� 
	for(int i=x;i>(x-y);i--){
		fenzi*=i;
	}
	//�����ĸ
	for(int i=y;i>0;i--){
		fenmu*=i;
	}
	return (fenzi/fenmu);
}
