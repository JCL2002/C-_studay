#include<bits/stdc++.h>
using namespace std;
int n,m;
int num;
int elf;
int NEXT;
char str[101][52];
int cp[101];//���Ĵ�ƥ��
bool test(int i,int j){//��������ַ����ǲ��ǻ��Ĵ�
	for(int k=0;k<m;k++){
		if(str[i][k]!=str[j][m-k-1])return 0;
	}
	return 1;
}
bool SELF(int i){
	for(int j=0;j<m/2;j++){
		if(str[i][j]!=str[i][m-j-1])return 0;
	}
	return 1;
}
void print(int depth){
	if(depth>=num){
		if(elf){
			cout <<str[elf];
		}
		return ;
	}
//	cout <<"������"<<endl;
	while(cp[NEXT]==0)NEXT++;
	int tmp=cp[NEXT];
	cout <<str[NEXT];
	cp[NEXT]=0;
	cp[tmp]=0;
	print(depth+1);
	cout <<str[tmp];
	
}
int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>str[i];
	}
	//���ж�һ���ַ����ܲ����������ַ����γɻ��Ĵ������ܵĻ����ж������ǲ��ǻ��Ĵ�
	for(int i=1;i<n;i++){//������е��໥���Ĵ�
		for(int j=i+1;j<=n;j++){
			//�ж�i��j�ǲ��ǻ��Ĵ�
			if(cp[i]==0&&cp[j]==0){
				if(test(i,j)){
					cp[i]=j;
					cp[j]=i;
					num++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cp[i])continue;
		if(SELF(i)){
			elf=i;
			break;
		}
	}
	if(elf){
		cout <<2*num*m+m<<endl;
	}
	else{
		cout <<2*num*m<<endl;
	}
//	cout <<"num:  "<<num<<endl;
//	cout <<"elf:  "<<elf<<endl;
	print(0);
	return 0;
}