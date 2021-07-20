#include<bits/stdc++.h>
using namespace std;

int arr[103];
int n;
bool cmp(int a,int b){
	return  a>b;
}


int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1,cmp);
	int sum=0;
	for(int i=1;i<n;i+=2){
		sum+=arr[i]-arr[i+1];
	}
	cout <<sum;
	
	return 0;
}