#include<bits/stdc++.h>
using namespace std;
//这个题给的内存比较大，不必释放
struct node{
	char num;
	bool end;//结束标志
	node* son[10];
};
bool test;
node* root=NULL;
string s;
node* init(node* root){
	root=(node*)malloc(sizeof(node));
	memset(root,0,sizeof(node));
	return root;
}
node* built(node* root,string& s,int depth){
	if(root==NULL){
		root=init(root);
	}
	else{
		if(root->end) test=0;
	}
	if(depth==(int)s.size()) root->end=1;
	if(depth<(int)s.size())root->son[s[depth]-'0']=built(root->son[s[depth]-'0'],s,depth+1);
	return root;
}

int main(){
	int t;
	cin >>t;
	while(t--){
		int n;cin >>n;
		test=1;
		while(n--){
			cin >>s;
			root=built(root,s,0);
		}
		if(test)cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
	}
	return 0;
}