#include<stdio.h>
int main(){
	int a[6][6];int n;int H_MAX[6],L_MIN[6];
	scanf("%d",&n);
	//����¼�� 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int max,min;
	//����������󲢰������H_MAX��
	for(int i=0;i<n;i++){
		max=a[i][0];
		for(int j=1;j<n;j++){
			if(max<a[i][j]) max=a[i][j];
		}
		H_MAX[i]=max;
	}
	//���ÿ�е���Сֵ���������H_MIN��
	for(int j=0;j<n;j++){
		min=a[0][j];
		for(int i=1;i<n;i++){
			if(min>a[i][j]) min=a[i][j];
		}
		L_MIN[j]=min;
	}
	//�����������ݣ���ǰ�����뵱ǰ�С��е����/Сֵ�����ʱ������ֵ
	int mark=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==H_MAX[i]&&a[i][j]==L_MIN[j]) {
				printf("%d %d",i,j);
				mark=1;
			}
		}
	}
	if(mark==0){
		printf("NONE");
	}
	return 0;
} 
