#include<stdio.h>
int main(){
	int PF(int x);
	int val(char x);
	char ip[33];int Ji_Shu=31,Out,Out_List[4];
	gets(ip);
	//�������飬����洢��Out_List�� 
	for(int i=3;i>=0;i--){
		Out=0;
		for(int j=0;j<8;j++,Ji_Shu--){
			Out+=PF(j)*val(ip[Ji_Shu]);
		}
		Out_List[i]=Out;
	}
	//�������
	for(int i=0;i<4;i++){
		printf("%d",Out_List[i]);
		if(i!=3) printf(".");
	}
	return 0;
}
//����2��x�η� 
int PF(int x){
	int out=1;
	for(int i=0;i<x;i++){
		out*=2;
	}
	return out;
}
//���������ַ���ת��Ϊ���� 
int val(char x){
	if(x=='0') return 0;
	else return 1;
}
