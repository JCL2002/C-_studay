#include<bits/stdc++.h>
using namespace std;
#define MAX 20
#define Type int
//��1Ϊ��ʼ����MAX����
Type tree[MAX+1];
Type lowbit(Type x){
	return x&(-x);
}
void add(Type x,int i){//��Ԫ��x�ӵ�������±�i��
	while(i<=MAX){
		tree[i]+=x;
		i+=lowbit(i);
	}
}
Type sum(int i){//������1+2+����+i
	Type res=0;
	while(i>0){
		res+=tree[i];
		i-=lowbit(i);
	}
	return res;
}
int main(){
	for(int i=1;i<=MAX;i++){
		add(i,i);
	}
	cout <<"sum���������"<<endl;
	for(int i=1;i<=MAX;i++){
		cout <<sum(i)<<' ';
	}
	return 0;
}