#include<bits/stdc++.h>
using namespace std;
//二叉树的BFS遍历(显示)用
queue<struct Node *>tree;
queue<struct Node *>cache;

struct Node{
	int k;
	int val;//权值
	string content;
	Node *l,*r;
};

void show(Node *root){//BFS来显示树
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

struct Node* rotate_left(struct Node* father,struct Node* son){//左旋函数
	father->r=son->l;
	son->l=father;
	return son;
}

struct Node* rotate_right(struct Node* father,struct Node* son){//右旋函数
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
	if(k>root->k){//大于当前节点，向右插
		root->r=insert(root->r,k,val,content);//插入右子树
		//根据权值判断是否需要旋转
		//本代码采用最大堆
		//判断是否需要进行旋转
		if(root->val<root->r->val){
			//左旋
			//父节点：root 子节点：root->r
			root=rotate_left(root,root->r);
		}
	}
	else if(k<root->k){
		root->r=insert(root->l,k,val,content);//插入左子树
		//同理
		if(root->val<root->l->val){
			//右旋
			//父节点：root 子节点：root->l
			root=rotate_right(root,root->l);
		}
	}
	else{
		cout << "元素重复";
		exit(1);
	}
	return root;
}

int main(){
	srand(time(NULL));
	struct Node *root=NULL;
	int k;string content;
	while(cin >> k >> content&&k){//输入0结束
		root=insert(root,k,rand(),content);
	}
	show(root);
	return 0;
}