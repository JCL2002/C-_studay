#include<stdio.h>
int main(){
	long long N,x,Pian_Yi;
	scanf("%lld",&N);
	for(x=1;(x*(x+1)<2*N);x++);//����ڵ�x���С� 
	Pian_Yi=(x*(x+1))/2-N;//���ƫ���� 
	//�����дӵ�һ�п�ʼ��ż���дӵ�һ�п�ʼ��
	if(x%2==0){
		printf("%lld/%lld",x-Pian_Yi,Pian_Yi+1);
	} 
	else{
		printf("%lld/%lld",Pian_Yi+1,x-Pian_Yi);
	}
}
