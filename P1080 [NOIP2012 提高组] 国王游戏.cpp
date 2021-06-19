#include<bits/stdc++.h>
using namespace std;
#define leng 4005 //高精度长度
struct Node{
	int left;
	int right;
};
Node arr[10002];
long long sum;//前n个人的乘积
bool cmp(Node a,Node b){
	return a.left*a.right<b.left*b.right;
}
//高精度
int power[leng];//相乘的结果
int tmp[leng];//缓存
int dive[leng];//除法结果
int dive_max[leng];//除法最大值
void init(int *a){//初始化数组
	for(int i=0;i<leng;i++){
		a[i]=0;
	}
}
void ti(int a){//高精度乘法
	int i=0;int low;
	init(tmp);
//	cout <<"乘数2： "<<a<<endl;
//	cout <<"原power数组后四位输出："<<power[3]<<" "<<power[2]<<" "<<power[1]<<" "<<power[0]<<endl;
	while(a){
		low=a%10;
		a/=10;
		for(int j=0;j<leng;j++){
			tmp[i+j]+=low*power[j];
		}
		i++;
	}
	//结果累加
	int carry=0;
	for(int j=0;j<leng;j++){
		carry=tmp[j]/10;
		power[j]=tmp[j]%10;
		if(carry){//当心最后一位爆掉
			tmp[j+1]+=carry;
		}
	}
//	cout <<"运算之后power数组后四位输出："<<power[3]<<" "<<power[2]<<" "<<power[1]<<" "<<power[0]<<endl;
	unsigned long long result=0;
	for(int j=leng-1;j>-1;j--){
		result*=10;
		result+=power[j];
//		cout <<"第"<<j<<"位： "<<power[j]<<endl;
	}
//	cout <<"乘法运算结果：  "<<result<<endl;
}
void di(int a){//高精度除法
	int remain=0;//余数
	for(int i=leng-1;i>-1;i--){
		remain*=10;
		remain+=power[i];
		dive[i]=remain/a;
		remain%=a;
	}
	//比较大小
	bool bigger=false;
	for(int i=leng-1;i>-1;i--){
		if(dive_max[i]<dive[i]){
			bigger=true;
			break;
		}
	}
	if(bigger){//拷贝
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
	unsigned long long dr=0ull;//最小数
	unsigned long long tmp;
	for(int i=1;i<=n;i++){
		ti(arr[i-1].left);
		di(arr[i].right);
//		cout <<"tmp: "<<tmp<<endl;;
		if(tmp>dr){
			dr=tmp;
		}
	}
	//结果输出
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