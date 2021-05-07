#include<bits/stdc++.h>
using namespace std;
#define MAX 20
#define Type int
//以1为起始，以MAX结束
Type tree[MAX+1];
Type lowbit(Type x){
	return x&(-x);
}
void add(Type x,int i){//将元素x加到数组的下标i处
	while(i<=MAX){
		tree[i]+=x;
		i+=lowbit(i);
	}
}
Type sum(int i){//求数组1+2+……+i
	Type res=0;
	while(i>0){
		res+=tree[i];
		i-=lowbit(i);
	}
	return res;
}
int main(){
	for(int i=1;i<=MAX;i++){
		add(i,i);
	}
	cout <<"sum数组输出："<<endl;
	for(int i=1;i<=MAX;i++){
		cout <<sum(i)<<' ';
	}
	return 0;
}