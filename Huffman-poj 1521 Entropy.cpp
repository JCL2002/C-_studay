#include<bits/stdc++.h>
using namespace std;
int times[256];//各个字母的出现次数
struct Node{
	char content;//'\0'表示空
	int times;//出现的次数;
	Node* l;
	Node* r;
};
void Sort(vector<Node> &arr){
	Node cache;
	for(int i=1;i<(int)arr.size();i++){
		for(int j=0;j<(int)arr.size()-i;j++){
			if(arr[j].times>arr[j+1].times){
				cache=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=cache;
			}
		}
	}
}
int dep(Node* root,char target,int depth){
	if(root==NULL){
		return -1;//找不到时返回-1；
	}
	if(root->content==target){
		return depth;
	}
	int j=dep(root->l,target,depth+1);
	if(j>0){
		return j;
	}
	else{
		return dep(root->r,target,depth+1);
	}
}
int main(){
	string str;cin >>str;
	vector<Node>arr;
	for(int i=0;i<(int)str.length();i++){
		times[(int)str[i]]++;//统计各个字符出现的次数
	}
	for(int i=0;i<256;i++){//把出现的字母放入vector容器arr中
		if(times[i]){
			Node cache;
			cache.times=times[i];
			cache.content=(char)i;
			cache.l=NULL;cache.r=NULL;//每个页子节点的左右指针为空
			arr.push_back(cache);
		}
	}
	Node* root=(Node*)malloc(sizeof(Node));//Huffman的根节点
	root->content=arr[0].content;root->times=arr[0].times;root->l=arr[0].l;root->r=arr[0].r;
	while(arr.size()>1){
		//考虑到数据量不大，用冒泡排序
		Sort(arr);
		root=(Node*)malloc(sizeof(Node));//树增高一层
		root->times=arr[0].times+arr[1].times;//权重累加
		root->content='\0';
		Node* l=(Node*)malloc(sizeof(Node));Node* r=(Node*)malloc(sizeof(Node));
		l->content=arr[0].content;l->times=arr[0].times;l->l=arr[0].l;l->r=arr[0].r;
		r->content=arr[1].content;r->times=arr[1].times;r->l=arr[1].l;r->r=arr[1].r;
		root->l=l;root->r=r;
		arr.push_back(*(root));
		arr.erase(arr.begin());arr.erase(arr.begin());
	}
	int ascii=8*(int)str.length();int huffman=0;
	for(int i=0;i<256;i++){//Huffman占用空间统计
		if(times[i]){
			huffman+=times[i]*dep(root,(char)i,0);
		}
	}
	cout <<ascii <<' '<<huffman<<' '<<(float)ascii/huffman;
	return 0;
}
//Huffman压缩