#include<stdio.h>
int main(){
	int N,M,temp;int a[1024],b[1024];
	scanf("%d %d",&N,&M);
	//����¼��
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	M=M%N;//�����M��N������
	//�ƶ�����
	for(int i=0;i<N;i++){
		if(i<(N-M)) {
			b[i+M]=a[i];
		}
		else {
			b[i-N+M]=a[i];
		}
	}
	for(int i=0;i<N-1;i++){
		printf("%d ",b[i]);
	}
	printf("%d",b[N-1]);//�����β�ո� 
	return 0; 
}
