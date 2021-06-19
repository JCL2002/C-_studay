#include<bits/stdc++.h>
using namespace std;
#define leng 4005 //�߾��ȳ���
struct Node{
	int left;
	int right;
};
Node arr[10002];
long long sum;//ǰn���˵ĳ˻�
bool cmp(Node a,Node b){
	return a.left*a.right<b.left*b.right;
}
//�߾���
int power[leng];//��˵Ľ��
int tmp[leng];//����
int dive[leng];//�������
int dive_max[leng];//�������ֵ
void init(int *a){//��ʼ������
	for(int i=0;i<leng;i++){
		a[i]=0;
	}
}
void ti(int a){//�߾��ȳ˷�
	int i=0;int low;
	init(tmp);
//	cout <<"����2�� "<<a<<endl;
//	cout <<"ԭpower�������λ�����"<<power[3]<<" "<<power[2]<<" "<<power[1]<<" "<<power[0]<<endl;
	while(a){
		low=a%10;
		a/=10;
		for(int j=0;j<leng;j++){
			tmp[i+j]+=low*power[j];
		}
		i++;
	}
	//����ۼ�
	int carry=0;
	for(int j=0;j<leng;j++){
		carry=tmp[j]/10;
		power[j]=tmp[j]%10;
		if(carry){//�������һλ����
			tmp[j+1]+=carry;
		}
	}
//	cout <<"����֮��power�������λ�����"<<power[3]<<" "<<power[2]<<" "<<power[1]<<" "<<power[0]<<endl;
	unsigned long long result=0;
	for(int j=leng-1;j>-1;j--){
		result*=10;
		result+=power[j];
//		cout <<"��"<<j<<"λ�� "<<power[j]<<endl;
	}
//	cout <<"�˷���������  "<<result<<endl;
}
void di(int a){//�߾��ȳ���
	int remain=0;//����
	for(int i=leng-1;i>-1;i--){
		remain*=10;
		remain+=power[i];
		dive[i]=remain/a;
		remain%=a;
	}
	//�Ƚϴ�С
	bool bigger=false;
	for(int i=leng-1;i>-1;i--){
		if(dive_max[i]<dive[i]){
			bigger=true;
			break;
		}
	}
	if(bigger){//����
		for(int i=0;i<leng;i++){
			dive_max[i]=dive[i];
		}
	}
}

int main(){
	int n;
	cin >>n;
	for(int i=0;i<=n;i++){
		scanf("%d %d",&arr[i].left,&arr[i].right);
	}
	sort(arr+1,arr+1+n,cmp);
	power[0]=1;
	unsigned long long dr=0ull;//��С��
	unsigned long long tmp;
	for(int i=1;i<=n;i++){
		ti(arr[i-1].left);
		di(arr[i].right);
//		cout <<"tmp: "<<tmp<<endl;;
		if(tmp>dr){
			dr=tmp;
		}
	}
	//������
	bool oup=false;
	for(int i=leng-1;i>-1;i--){
		if(dive_max[i]){
			oup=true;
		}
		if(oup){
			printf("%d",dive_max[i]);
		}
	}
	printf("\n");
	return 0;
}