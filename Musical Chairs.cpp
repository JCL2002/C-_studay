#include<bits/stdc++.h>
using namespace std;
int n;

int tree[10003];//树状数组

int arr[10003];

int lowbit(int x){
	return x&-x;
}

void add(int x){
	while(x<=n){
		tree[x]++;
		x+=lowbit(x);
	}
}

int sum(int x){
	int sum=0;
	while(x>0){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

int f(int x){//映射函数，讲动态区间的x映射成静态区间
	int tmp=x;
	while(x!=tmp-sum(tmp)){
		tmp+=x-(tmp-sum(tmp));
	}
	return tmp;
}

void del(int x){//删除动态区间的第x个元素，重新映射
	int tmp=x;
	while(x!=tmp-sum(tmp)){
		tmp+=x-(tmp-sum(tmp));
	}
	add(tmp);
}

int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	}
	int x=1;
	for(int i=n;i>1;i--){//踢人
		int y=f(x);
		x=(arr[y]+x-1)%i;
		if(x==0) x=i;
		del(x);
		x%=i-1;
		if(x==0) x=i-1;
	}
	cout <<f(x)<<endl;
	return 0;
}