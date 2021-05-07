#include<bits/stdc++.h>
using namespace std;
#define Type int//定义线段树用来处理的数据类型
#define MM max//定义线段树节点存储的是最大值还是最小值
#define MAX 20//定义线段树用来处理的数组的长度,不超过int的长度
Type arr[MAX];
struct Node {
	Type val;//树的节点内容
	int l_a;//区间左端点
	int r_a;//区间右端点
	Node* l;//左子树
	Node* r;//右子树
};
Node* built(int l_a,int r_a){//构建线段树,传入区间左端点和右端点
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
		只要当前节点的区间长度不为1，则它必定有两个子节点,即当前节点只要有子节点，必有两个子节点
		当前节点的val值就是他的两个子树值的MM
		*/
	}
	return root;
}
Type find(Node* root,int l_a,int r_a){//查询区间段的MM值
	if(l_a==root->l_a&&r_a==root->r_a){
		return root->val;
	}
	else{
		int mid=(root->l_a+root->r_a)/2;
		if(l_a>mid){//完全位于右半段
			return find(root->r,l_a,r_a);
		}
		else if(r_a<=mid){//完全位于左半段
			return find(root->l,l_a,r_a);
		}
		else{//介于两者中间
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
		if(i<=mid){//左半段
			root->val=MM(root->r->val,change(root->l,content,i));
			return root->val;
		}
		else{//右半段
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
	cout <<"请输入操作的次数：";
	int n;cin >>n;
	root=built(0,MAX-1);
	cout <<"请依次输入下标 内容进行更改"<<endl;
	for(int i=0;i<n;i++){
		int j,k;
		cin >>j>>k;
		change(root,k,j);
	}
	cout <<"数组打印："<<endl;
	for(int i=0;i<MAX;i++){
		cout <<arr[i]<<' ';
	}
	cout <<"请输入要查询的次数："<<endl;
	cin >>n;
	for(int i=0;i<n;i++){
		int j,k;
		cin >>j>>k;
		cout <<"max :"<<find(root,j,k)<<endl;
	}
	return 0;
}