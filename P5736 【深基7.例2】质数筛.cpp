#include<bits/stdc++.h>
using namespace std;
int arr[103];
bool prim(int x){
	if(x<2)return 0;
	if(x==2) return 1;
	for(int i=2;i<sqrt(x)+1;i++){
		if(x%i==0)return 0;
	}
	return 1;
}
int main(){
	int n;
	cin >>n;
	for(int i=0;i<n;i++){
		cin >>arr[i];
	}
	for(int i=0;i<n;i++){
		if(prim(arr[i]))cout <<arr[i]<<' ';
	}
	return 0;
}