#include<bits/stdc++.h>
using namespace std;
#define Type int//�����߶��������������������
#define MM max//�����߶����ڵ�洢�������ֵ������Сֵ
#define MAX 20//�����߶����������������ĳ���,������int�ĳ���
Type arr[MAX];
struct Node {
	Type val;//���Ľڵ�����
	int l_a;//������˵�
	int r_a;//�����Ҷ˵�
	Node* l;//������
	Node* r;//������
};
Node* built(int l_a,int r_a){//�����߶���,����������˵���Ҷ˵�
	Node* root=(Node*)malloc(sizeof(Node));
	if(l_a==r_a){
		root->l_a=l_a;root->r_a=r_a;
		root->l=NULL;root->r=NULL;
		root->val=arr[l_a];
	}
	else{
		root->l_a=l_a;root->r_a=r_a;
		root->l=built(l_a,(l_a+r_a)/2);
		root->r=built((l_a+r_a)/2+1,r_a);
		root->val=MM(root->l->val,root->r->val);
		/*
		ֻҪ��ǰ�ڵ�����䳤�Ȳ�Ϊ1�������ض��������ӽڵ�,����ǰ�ڵ�ֻҪ���ӽڵ㣬���������ӽڵ�
		��ǰ�ڵ��valֵ����������������ֵ��MM
		*/
	}
	return root;
}
Type find(Node* root,int l_a,int r_a){//��ѯ����ε�MMֵ
	if(l_a==root->l_a&&r_a==root->r_a){
		return root->val;
	}
	else{
		int mid=(root->l_a+root->r_a)/2;
		if(l_a>mid){//��ȫλ���Ұ��
			return find(root->r,l_a,r_a);
		}
		else if(r_a<=mid){//��ȫλ������
			return find(root->l,l_a,r_a);
		}
		else{//���������м�
			return MM(find(root->l,l_a,mid),find(root->r,mid+1,r_a));
		}
	}
}
Type change(Node* root,Type content,int i){
	if(root->l_a==root->r_a&&root->l_a==i){
		arr[i]=content;
		root->val=content;
		return root->val;
	}
	else{
		int mid=(root->l_a+root->r_a)/2;
		if(i<=mid){//����
			root->val=MM(root->r->val,change(root->l,content,i));
			return root->val;
		}
		else{//�Ұ��
			root->val=MM(root->l->val,change(root->r,content,i));;
			return root->val;
		}
	}
}
int main(){
	Node* root=NULL;
	for(int i=0;i<MAX;i++){
		cin >>arr[i];
	}
	cout <<"����������Ĵ�����";
	int n;cin >>n;
	root=built(0,MAX-1);
	cout <<"�����������±� ���ݽ��и���"<<endl;
	for(int i=0;i<n;i++){
		int j,k;
		cin >>j>>k;
		change(root,k,j);
	}
	cout <<"�����ӡ��"<<endl;
	for(int i=0;i<MAX;i++){
		cout <<arr[i]<<' ';
	}
	cout <<"������Ҫ��ѯ�Ĵ�����"<<endl;
	cin >>n;
	for(int i=0;i<n;i++){
		int j,k;
		cin >>j>>k;
		cout <<"max :"<<find(root,j,k)<<endl;
	}
	return 0;
}