#include<bits/stdc++.h>
using namespace std;
struct AR{
	bool color;//false�����ɫ��true������ɫ
	int val;//��ֵ
};
AR arr[1000001];
struct Node{
	bool choose;//�Ƿ�ѡ��
	bool color;//��ɫ,��ɫΪfalse
	int val;//��ѡ������ļ�ֵ
	int max_of_b;//��ɫ���ֵ
};
Node Link[1000001]={false,false,0,0};
int main(){
	int t,n,m;
	cin >>t;
	for(int i=0;i<t;i++){
		cin >>n>>m;
		//1������
		for(int j=0;j<n;j++){//��ֵ¼��
			for(int k=0;k<m;k++){
				scanf("%d",&arr[j*m+k].val);
			}
		}
		for(int j=0;j<t;j++){
			for(int k=0;k<m;k++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp){
					arr[j*m+k].color=true;
				}
				else{
					arr[j*m+k].color=false;
				}
			}
		}
		//̰�ģ�ֻҪ��ǰ��ѡ�������ĸ�����ɫ��һ��ѡ
		for(int j=0;j<n;j++){
			//�ұ�ѡ�е����ֵ
			int max_i=0,max=arr[j*m].val;
			for(int k=1;k<m;k++){
				if(arr[j*m+k].val>max){
					max=arr[j*m+k].val;
					max_i=k;
				}
			}
			//�ж������ǲ�����ɫ
			if(arr[max_i].color){
				Link[j].choose=true;
				Link[j].color=true;
				Link[j].val=max;
			}
			else{
				Link[j].choose=false;
				Link[j].color=false;
				Link[j].val=max;
			}
		}
		//̰�ģ�ֻҪ��������ɫ��ס�����ֵΪ��ɫ��Ҳһ��ѡ��
		for(int j=0;j<n;j++){
			//��β����
			if(j==0){
				if(Link[1].color){
					Link[j].choose=true;
				}
			}
			else if(j==n-1){
				if(Link[j-1].color){
					Link[j].choose=true;
				}
			}
			//��������ж����ڵ�����
			else if(!Link[j].color){
				if(Link[j-1].color&&Link[j+1].color){
					Link[j].choose=true;
				}
			}
		}
		//��û��ѡ�е���ɫ�����ֵ�����ж�̬�滮
		for(int j=0;j<n;j++){
			int max=-1;//��֪����һ���ǲ�����ɫ
			for(int k=0;k<m;k++){
				if(arr[j*m+k].color){
					if(arr[j*m+k].val>max){
						max=arr[j*m+k].val;
					}
				}
			}
			Link[j].max_of_b=max;
		}
		//��̬�滮
		for(int j=1;j<n;j++){
			if(Link[j].choose==false){
				if(Link[j-1].color){//��һ��Ϊ����ֱ��ѡ
					Link[j].choose=true;
				}
				else if(Link[j].val+Link[j-1].max_of_b>Link[j].max_of_b+Link[j-1].val){
					Link[j-1].color=true;
					Link[j].choose=true;
				}
			}
		}
		long long sum=0;
		for(int j=0;j<n;j++){
			if(Link[j].color){
				sum+=(long long)Link[j].val;
			}
			else{
				sum+=(long long)Link[j].max_of_b;
			}
		}
		cout <<sum<<endl;
	}
	return 0;
}