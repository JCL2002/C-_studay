#include<stdio.h>
int main(){
	int n,a[10][10];long long sum=0;
	scanf("%d",&n);
	//����¼�� 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//�ȼ�������Ԫ�ص��ܺ��ټ�ȥ��ӦԪ��
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum+=a[i][j];
		}
	}
	//��ȥ���һ��
	for(int j=0;j<n;j++){
		sum-=a[n-1][j];
	}
	//��ȥ���һ��
	for(int i=0;i<n;i++){
		sum-=a[i][n-1];
	}
	//��ȥ���Խ���
	for(int i=0;i<n;i++){
		sum-=a[i][n-1-i];
	}
	//�������һ��Ԫ��,���½�Ԫ�أ����Ͻǣ���Ϊ���Ǳ�����2��
	sum+=a[n-1][n-1];
	sum+=a[n-1][0];
	sum+=a[0][n-1]; 
	printf("%lld",sum);
}
