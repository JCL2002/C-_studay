#include<stdio.h>
int main(){
	int a[3][4];int max;
	for (int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	max=a[0][0];
	//�����ֵ 
	for (int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(max<a[i][j]){
				max=a[i][j];
			}
		}
	}
	//��Ѱ��Сֵ�ھ����е�λ��	 
	for (int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(max==a[i][j]){
				printf("%d %d %d\n",max,i,j);
			}
		}
	}
	return 0;
}
