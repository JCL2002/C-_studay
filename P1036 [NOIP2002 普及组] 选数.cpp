#include<bits/stdc++.h>
using namespace std;
int number=0;
int L[20];
bool prim(int n){//判断是不是质数
	if(n==2){
		return true;
	}
	else if(n%2==0){//偶数
		return false;
	}
	else{
		for(int j=3;j<sqrt(n)+1;j+=2){
			if(n%j==0){
				return false;
			}
		}
		return true;
	}
}
void emulate(int head,int element,int N,int val){//枚举
	if(!element){
		if(prim(val)){
			number++;
		}
		return ;
	}
	for(int j=0;j<N-element-head+1;j++){
		emulate(head+j+1,element-1,N,val+L[head+j]);
	}
}
int main(){
	int N,element;
	cin >> N >> element;
	for(int j=0;j<N;j++){
		cin >> L[j];
	}
	emulate(0,element,N,0);
	cout << number;
	return 0;
}