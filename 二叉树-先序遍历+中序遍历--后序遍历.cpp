#include<bits/stdc++.h>
using namespace std;
vector<int>first;
vector<int>media;
int p=0;
struct Node{
	int val;
	Node *l,*r;
}head;
int find_i(int a){
	int i;
	for(i=0;i<media.size();i++){
		if(a==media[i]){
			return i;
		}
	}
	cout << "录入数据有误!";
	exit(1);
}
struct Node *built(int left,int right){
	if(right-left<0){//结束
		return NULL;
	}
	struct Node *head=(struct Node *)malloc(sizeof(struct Node));
	head->val=first[p];p++;
	int middle=find_i(head->val);
	head->l=built(left,middle-1);
	head->r=built(middle+1,right);
	return head;
}
void last(struct Node *head){
	if(head==NULL){
		return;
	}
	last(head->l);
	last(head->r);
	cout << head->val << " ";
	return;
}
int main(){
	int number,i,input;
	cin >> number;
	for(i=0;i<number;i++){
		cin >> input;
		first.push_back(input);
	}
	for(i=0;i<number;i++){
		cin >> input;
		media.push_back(input);
	}
	struct Node *head;
	head=built(0,number-1);
	last(head);
	return 0;
}