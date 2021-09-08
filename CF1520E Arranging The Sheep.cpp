#include<bits/stdc++.h>
using namespace std;
int arr[1000006];
char s[1000006];
int n,m;
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		m=0;
		cin >>s;
		for(int i=0;i<n;i++){
			if(s[i]=='*')arr[++m]=i;
		}
		int mid=arr[(1+m)/2];
		int mid_i=(1+m)/2;
		long long sum=0;
		for(int i=1;i<=m;i++){
			sum+=abs(abs(arr[i]-mid)-abs(i-mid_i));
		}
		cout <<sum<<endl;
	}
	return 0;
}