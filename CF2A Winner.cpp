#include<bits/stdc++.h>
using namespace std;
struct recard{//NAS里面的链表
	int time;//场次
	int sum;//记录到当前场次的分数
	recard* n;
};
struct NAS{
	char name[33];
	int final;//最终得分
	recard root;
};
int rcd(recard &root,int add,int time){//向当前选手添加比赛记录,返回分数总和
	if(root.n==NULL){
		root.n=(recard*)malloc(sizeof(recard));
		root.n->n=NULL;root.n->sum=root.sum+add;root.n->time=time;
//		cout <<"time:"<<root.time<<"   sum:"<<root.sum<<endl;
		return root.sum+add;
	}
	else{
//		cout <<"time:"<<root.time<<"   sum:"<<root.sum<<endl;
		return rcd(*(root.n),add,time);
	}
}
int Find(recard root,int sum){//返回第一个大于sum的位置
	if(root.sum>=sum) return root.time;
	else return Find(*(root.n),sum);
}
vector<NAS>arr;
void add(char* name,int score,int time){
	bool only=true;//标志名字是否出现过
	int j=0;
	for(int i=0;i<(int)arr.size();i++){
//		cout <<arr[i].name <<"     "<<name<<endl;
		if(strcmp(arr[i].name,name)==0) {
//			cout <<"重名"<<endl;
			only=false;
			j=i;
			break;
		}
	}
//	cout <<"准备添加"<<endl;
	if(only){
//		cout <<"唯一的"<<endl;
		arr.resize(arr.size()+1);
//		cout <<"向量扩容完毕"<<endl;
		strcpy(arr[(int)arr.size()-1].name,name);
//		cout <<"字符串复制完毕"<<endl;
		arr[(int)arr.size()-1].root.n=NULL;arr[(int)arr.size()-1].root.sum=score;arr[(int)arr.size()-1].root.time=time;arr[(int)arr.size()-1].final=score;
//		arr[(int)arr.size()-1].final=rcd(arr[(int)arr.size()-1].root,score,time);
	}
	else{
		strcpy(arr[j].name,name);
		arr[j].final=rcd(arr[j].root,score,time);
//		cout <<arr[j].name <<"的分数："<<arr[j].final<<endl;
	}
//	cout <<"添加完毕"<<endl;
}
int main(){
	char name[33];int score,t;
	cin >>t;
	for(int i=0;i<t;i++){
		scanf("%s %d",name,&score);
		add(name,score,i);
	}
//	cout <<"人数："<<arr.size()<<endl;
	int max=arr[0].final;
//	cout <<"最大值初始值";
	for(int i=1;i<(int)arr.size();i++){//找出最大值
		if(arr[i].final>max){
			max=arr[i].final;
		}
	}
//	cout <<"最大值："<<max<<endl;
	int number_of_max=0;//同时有最大分数的人数
	for(int i=0;i<(int)arr.size();i++){
		if(arr[i].final==max){
			number_of_max++;
		}
	}
//	cout <<"同时最大人数："<<number_of_max<<endl;
	int first=t;//第一次出现
	for(int i=0;i<(int)arr.size();i++){
		if(arr[i].final==max){
			int cache=Find(arr[i].root,max);
			if(cache<first){
				first=cache;
				strcpy(name,arr[i].name);
			}
		}
	}
	cout <<name;
	return 0;
}