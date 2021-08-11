#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	bool end;//结束标志 
	bool call;//点名标志
	node* son[27];
};
node* root;
int n,m;
void insert(node* root,string& s,int depth){
	if(depth==(int)s.size())return ;
//	cout <<"到这了"<<endl;
//	cout <<"深度： "<<depth;
	if(root->son[s[depth]-'a'+1]==NULL){
//		cout <<"  if"<<endl;
		root->son[s[depth]-'a'+1]=(node*)malloc(sizeof(node));
		root->son[s[depth]-'a'+1]->c=s[depth];
		if(depth+1==(int)s.size()) root->son[s[depth]-'a'+1]->end=1;
		for(int i=0;i<27;i++){
			root->son[s[depth]-'a'+1]->son[i]=NULL;
		}
		root->son[s[depth]-'a'+1]->call=0;
		insert(root->son[s[depth]-'a'+1],s,depth+1);
	}
	else{
//		cout <<"   else"<<endl;
		insert(root->son[s[depth]-'a'+1],s,depth+1);
	}
}
void search(node* root,string& s,int depth){
	if(root==NULL){
		cout <<"WRONG"<<endl;
		return;
	}
	if(depth==(int)s.size()){
		if(root->end){
			if(root->call){
				cout <<"REPEAT"<<endl;
				return;
			}
			else{
				cout <<"OK"<<endl;
				root->call=1;
				return ;
			}
		}
		else{//没有这个名字
			cout <<"WRONG"<<endl;
			return ;
		}
	}
	else{
		search(root->son[s[depth]-'a'+1],s,depth+1);
	}
}
int main(){
	cin >>n;
	string s;
	root=(node*)malloc(sizeof(node));
	for(int i=0;i<27;i++){
		root->son[i]=NULL;
	}
	root->c='\0';
	root->call=0;
	root->end=0;
	for(int i=0;i<n;i++){
		cin >>s;
		insert(root,s,0);
	}
	cin >>m;
	for(int i=0;i<m;i++){
		cin >>s;
		search(root,s,0);
	}
	return 0;
}