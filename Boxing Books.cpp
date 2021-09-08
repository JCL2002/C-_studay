#include<bits/stdc++.h>
using namespace std;
#define Type int//�����߶��������������������
#define MM max//�����߶����ڵ�洢�������ֵ������Сֵ
#define MAX 1003//�����߶����������������ĳ���,������int�ĳ���
int n,k;
struct book{
	int w;
	int h;
};
book arr[1003];
long long sum[1003];//��ȵ�ǰ׺������
struct Node {
	Type val;//���Ľڵ�����
	int l_a;//������˵�
	int r_a;//�����Ҷ˵�
	Node* l;//������
	Node* r;//������
};
Node* root;
Node* built(int l_a,int r_a){//�����߶���,����������˵���Ҷ˵�
	Node* root=(Node*)malloc(sizeof(Node));
	if(l_a==r_a){
		root->l_a=l_a;root->r_a=r_a;
		root->l=NULL;root->r=NULL;
		root->val=arr[l_a].h;
	}
	else{
		root->l_a=l_a;root->r_a=r_a;
		root->l=built(l_a,(l_a+r_a)/2);
		root->r=built((l_a+r_a)/2+1,r_a);
		root->val=MM(root->l->val,root->r->val);
		/*
		ֻҪ��ǰ�ڵ�����䳤�Ȳ�Ϊ1�������ض��������ӽڵ�,����ǰ�ڵ�ֻҪ���ӽڵ㣬���������ӽڵ�
		��ǰ�ڵ��valֵ����������������ֵ��MM
		*/
	}
	return root;
}
Type Find(Node* root,int l_a,int r_a){//��ѯ����ε�MMֵ
	if(l_a==root->l_a&&r_a==root->r_a){
		return root->val;
	}
	else{
		int mid=(root->l_a+root->r_a)/2;
		if(l_a>mid){//��ȫλ���Ұ��
			return Find(root->r,l_a,r_a);
		}
		else if(r_a<=mid){//��ȫλ������
			return Find(root->l,l_a,r_a);
		}
		else{//���������м�
			return MM(Find(root->l,l_a,mid),Find(root->r,mid+1,r_a));
		}
	}
}
int dp[1003][1003];//��һ���������״̬���ڶ����������ӵ�״̬
int main(){
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>arr[i].w>>arr[i].h;
	}
	root=built(1,n);//�������ֵ�߶���
	//������ǰ׺������
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i].w;
	}
	//��ʼ����
	for(int i=1;i<=n;i++){
		dp[i][1]=sum[i]*Find(root,1,i);
	}
	for(int i=2;i<=k;i++){//�ȴ�һ�����ӿ�ʼö��
		for(int j=i;j<=n;j++){//j����ǰj����װ��k-1���������棻
			long long mmin=1e18;
			for(int h=i-1;h<j;h++){
				mmin=min(mmin,dp[h][i-1]+Find(root,h+1,j)*(sum[j]-sum[h]));
			}
			dp[j][i]=mmin;
		}
	}
//	cout <<endl;
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++)cout <<dp[j][i]<<" ";
//		cout <<endl;
//	}
	cout <<dp[n][k];
	return 0;
}