#include<bits/stdc++.h>
using namespace std;
struct recard{//NAS���������
	int time;//����
	int sum;//��¼����ǰ���εķ���
	recard* n;
};
struct NAS{
	char name[33];
	int final;//���յ÷�
	recard root;
};
int rcd(recard &root,int add,int time){//��ǰѡ����ӱ�����¼,���ط����ܺ�
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
int Find(recard root,int sum){//���ص�һ������sum��λ��
	if(root.sum>=sum) return root.time;
	else return Find(*(root.n),sum);
}
vector<NAS>arr;
void add(char* name,int score,int time){
	bool only=true;//��־�����Ƿ���ֹ�
	int j=0;
	for(int i=0;i<(int)arr.size();i++){
//		cout <<arr[i].name <<"     "<<name<<endl;
		if(strcmp(arr[i].name,name)==0) {
//			cout <<"����"<<endl;
			only=false;
			j=i;
			break;
		}
	}
//	cout <<"׼�����"<<endl;
	if(only){
//		cout <<"Ψһ��"<<endl;
		arr.resize(arr.size()+1);
//		cout <<"�����������"<<endl;
		strcpy(arr[(int)arr.size()-1].name,name);
//		cout <<"�ַ����������"<<endl;
		arr[(int)arr.size()-1].root.n=NULL;arr[(int)arr.size()-1].root.sum=score;arr[(int)arr.size()-1].root.time=time;arr[(int)arr.size()-1].final=score;
//		arr[(int)arr.size()-1].final=rcd(arr[(int)arr.size()-1].root,score,time);
	}
	else{
		strcpy(arr[j].name,name);
		arr[j].final=rcd(arr[j].root,score,time);
//		cout <<arr[j].name <<"�ķ�����"<<arr[j].final<<endl;
	}
//	cout <<"������"<<endl;
}
int main(){
	char name[33];int score,t;
	cin >>t;
	for(int i=0;i<t;i++){
		scanf("%s %d",name,&score);
		add(name,score,i);
	}
//	cout <<"������"<<arr.size()<<endl;
	int max=arr[0].final;
//	cout <<"���ֵ��ʼֵ";
	for(int i=1;i<(int)arr.size();i++){//�ҳ����ֵ
		if(arr[i].final>max){
			max=arr[i].final;
		}
	}
//	cout <<"���ֵ��"<<max<<endl;
	int number_of_max=0;//ͬʱ��������������
	for(int i=0;i<(int)arr.size();i++){
		if(arr[i].final==max){
			number_of_max++;
		}
	}
//	cout <<"ͬʱ���������"<<number_of_max<<endl;
	int first=t;//��һ�γ���
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