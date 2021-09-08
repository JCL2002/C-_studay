#include<bits/stdc++.h>
using namespace std;
#define Type int//定义线段树用来处理的数据类型
#define MM max//定义线段树节点存储的是最大值还是最小值
#define MAX 1003//定义线段树用来处理的数组的长度,不超过int的长度
int n,k;
struct book{
	int w;
	int h;
};
book arr[1003];
long long sum[1003];//宽度的前缀和数组
struct Node {
	Type val;//树的节点内容
	int l_a;//区间左端点
	int r_a;//区间右端点
	Node* l;//左子树
	Node* r;//右子树
};
Node* root;
Node* built(int l_a,int r_a){//构建线段树,传入区间左端点和右端点
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
		只要当前节点的区间长度不为1，则它必定有两个子节点,即当前节点只要有子节点，必有两个子节点
		当前节点的val值就是他的两个子树值的MM
		*/
	}
	return root;
}
Type Find(Node* root,int l_a,int r_a){//查询区间段的MM值
	if(l_a==root->l_a&&r_a==root->r_a){
		return root->val;
	}
	else{
		int mid=(root->l_a+root->r_a)/2;
		if(l_a>mid){//完全位于右半段
			return Find(root->r,l_a,r_a);
		}
		else if(r_a<=mid){//完全位于左半段
			return Find(root->l,l_a,r_a);
		}
		else{//介于两者中间
			return MM(Find(root->l,l_a,mid),Find(root->r,mid+1,r_a));
		}
	}
}
int dp[1003][1003];//第一个代表书的状态，第二个代表箱子的状态
int main(){
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>arr[i].w>>arr[i].h;
	}
	root=built(1,n);//建立最大值线段树
	//计算宽度前缀和数组
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i].w;
	}
	//开始动规
	for(int i=1;i<=n;i++){
		dp[i][1]=sum[i]*Find(root,1,i);
	}
	for(int i=2;i<=k;i++){//先从一个箱子开始枚举
		for(int j=i;j<=n;j++){//j代表前j个书装到k-1个箱子里面；
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