#include<bits/stdc++.h>
using namespace std;
char last[9];
char mid[9];
int k;
struct Node{
	char c;
	Node *l,*r;
};
int find(char c){
	for(int j=0;j<strlen(mid);j++){
		if(c==mid[j]){
			return j;
		}
	}
	cout <<"ÊäÈëÓÐÎó";
	exit(1);
}
Node* built(char c,int l,int r){
	if(r-l<0){
		return NULL;
	}
	Node* root=(Node *)malloc(sizeof(Node));
	root->c=c;
	k--;
	root->r=built(last[k],find(c)+1,r);
	root->l=built(last[k],l,find(c)-1);
	return root;
}
void Mid(Node* root){
	if(root==NULL){
		return;
	}
	
	cout << root->c;
	Mid(root->l);
	Mid(root->r);
}
int main(){
	Node* root=NULL;
	scanf("%s",mid);
	scanf("%s",last);
	k=strlen(mid)-1;
	root=built(last[k],0,k);
	Mid(root);
	return 0;
}