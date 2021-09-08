#include<bits/stdc++.h>
using namespace std;
int arr[105];
int n;
void swap(int& a,int& b){
	int c=a;
	a=b;
	b=c;
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++)arr[i]=i;
		for(int i=1;i<n;i++) swap(arr[i],arr[i+1]);
		for(int i=1;i<=n;i++) cout <<arr[i]<<" ";
		cout <<endl;
	}
	return 0;
}