#include<bits/stdc++.h>
using namespace std;
//��������BFS����(��ʾ)��
queue<struct Node *>tree;
queue<struct Node *>cache;

struct Node{
	int k;
	int val;//Ȩֵ
	string content;
	Node *l,*r;
};

void show(Node *root){//BFS����ʾ��
	if(root->l!=NULL){
		tree.push(root->l);
	}
	if(root->r!=NULL){
		tree.push(root->r);
	}
	cout << root->content <<"(" <<root->val<<")" <<"\n";
	while(!tree.empty()){
		int j=tree.size();
		for(int i=0;i<j;i++){
			root=tree.front();tree.pop();
			cout << root->content <<"(" <<root->val<<")";
			if(root->l!=NULL){
				tree.push(root->l);
			}
			if(root->r!=NULL){
				tree.push(root->r);
			}
		}
		cout << "\n";
	}
}

struct Node* rotate_left(struct Node* father,struct Node* son){//��������
	father->r=son->l;
	son->l=father;
	return son;
}

struct Node* rotate_right(struct Node* father,struct Node* son){//��������
	father->l=son->r;
	son->r=father;
	return son;
}

struct Node* insert(struct Node *root,int k,int val,string content){
	if(root==NULL){
		struct Node* rot=(struct Node*)malloc(sizeof(struct Node));
		rot->k=k;rot->val=val;rot->content=content;rot->l=NULL;rot->r=NULL;
		return rot;
	}
	if(k>root->k){//���ڵ�ǰ�ڵ㣬���Ҳ�
		root->r=insert(root->r,k,val,content);//����������
		//����Ȩֵ�ж��Ƿ���Ҫ��ת
		//�������������
		//�ж��Ƿ���Ҫ������ת
		if(root->val<root->r->val){
			//����
			//���ڵ㣺root �ӽڵ㣺root->r
			root=rotate_left(root,root->r);
		}
	}
	else if(k<root->k){
		root->r=insert(root->l,k,val,content);//����������
		//ͬ��
		if(root->val<root->l->val){
			//����
			//���ڵ㣺root �ӽڵ㣺root->l
			root=rotate_right(root,root->l);
		}
	}
	else{
		cout << "Ԫ���ظ�";
		exit(1);
	}
	return root;
}

int main(){
	srand(time(NULL));
	struct Node *root=NULL;
	int k;string content;
	while(cin >> k >> content&&k){//����0����
		root=insert(root,k,rand(),content);
	}
	show(root);
	return 0;
}