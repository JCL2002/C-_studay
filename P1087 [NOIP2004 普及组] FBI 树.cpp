#include<bits/stdc++.h>
using namespace std;
struct Node{//�������ڵ�
	char name;
	Node* l;
	Node* r;
};
#define Type  int //���庯���Ĵ���ͷ�������
Type power(Type x,Type n){//x��n�η�,������
	Type res=1;
	while(n){
		if(n&1) res*=x;
		x*=x;
		n>>=1;
	}
	return res;
}
char type(char *c,int l,int r){//��ȡ�ַ�������
	int z=0,o=0;
	for(int i=0;i<=r-l;i++){
		if(c[l+i]=='0'){
			z++;
		}
		else{
			o++;
		}
		if(z&&o){
			return 'F';
		}
	}
	if(z){
		return 'B';
	}
	else{
		return 'I';
	}
}
Node* built(char* content,char name ,int l,int r){//����������
	Node* root=(Node*)malloc(sizeof(Node));
	root->name=name;
	if(r-l==0){
		root->l=NULL;
		root->r=NULL;
		return root;
	}
	root->l=built(content,type(content,l,l+(r-l)/2),l,l+(r-l)/2);
	root->r=built(content,type(content,r-(r-l)/2,r),r-(r-l)/2,r);
	return root;
}
void last(Node* root){//�������������
	if(root==NULL) return ;
	last(root->l);
	last(root->r);
	printf("%c",root->name);
	return ;
}
int main(){
	int n;
	cin >>n;getchar();
	char *content;
	content=(char*)malloc(sizeof(char)*power(2,n));
	string str;
	cin >>str;
	for(int i=0;i<power(2,n);i++){
		content[i]=str[i];
	}
	Node* root;
	root=built(content,type(content,0,power(2,n)-1),0,power(2,n)-1);
	last(root);
	return 0;
}