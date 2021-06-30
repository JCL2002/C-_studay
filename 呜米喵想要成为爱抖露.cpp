#include<bits/stdc++.h>
using namespace std;
//��С������
int n,m;
long long k;
bool prime(int n){//�����ж�
	if(n==1)return false;
	if(n<4) return true;
	if(n%2==0) return false;
	for(int i=3;i<=sqrt(n)+1;i+=2){
		if(n%i==0)return false;
	}
	return true;
}
int arr[200008];
struct road{
	int s;
	int e;
	int len;
};
road R[200008];
bool cmp(road a,road b){
	return a.len<b.len;
}
//���鼯

void init(){//�����ʼ�� 
	int i;
	for(i=0;i<=n+2;i++){
		arr[i]=i;
	}
} 

int find_root(int a){//�Ҹ� 
	int a_o=a,next; 
	while(true){
		if(arr[a]==a){
			break;//��ʱa���Ǹ� 
		}
		else{
			a=arr[a];
		}
	}
	//·��ѹ��
	while(true){
		if(a_o==a){
			return a;
		}
		else{
			next=arr[a_o];
			arr[a_o]=a;//ͳһָ���
			a_o=next; 
		}
	}
}

void Union(int a,int b){
	int root_a,root_b;
	root_a=find_root(a);root_b=find_root(b);
	arr[root_a]=root_b;
}

int main(){
	cin >>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&R[i].s,&R[i].e,&R[i].len);
		if(prime(R[i].len)) {
//			cout <<R[i].len<<"������"<<endl;
			R[i].len=0;//��������
		}
	}
	init();
	sort(R+1,R+m+1,cmp);
//	for(int i=1;i<=m;i++){
//		cout <<R[i].s<<"   "<<R[i].e<<"  "<<R[i].len<<endl;
//	}
	long long sum=0;
	for(int i=1;i<=m;i++){
//		cout <<find_root(R[i].s) <<"   "<<find_root(R[i].e)<<endl;
		if(find_root(R[i].s)!=find_root(R[i].e)){
			Union(R[i].s,R[i].e);
			sum+=R[i].len;
		}
	}
	int ROOT=find_root(1);
	bool on=true;
	for(int i=2;i<=n;i++){
		if(ROOT!=find_root(i)){
			on=false;
			break;
		}
	}
	if(sum<k&&on){
		cout <<"wmmxycwdjdwdlnljbzwtskirakira";
	}
	else{
		cout <<"wmmxycwdjdwdlnljbzwtsfljt";
	}
	return 0;
}