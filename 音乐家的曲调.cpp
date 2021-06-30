#include<bits/stdc++.h>
using namespace std;
int arr[100006];
int sum[100006];
int n,m;
int main(){
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=n;i>0;i--){
		if(arr[i]<arr[i+1]){
			sum[i]=sum[i+1]+1;
		}
		else{
			sum[i]=sum[i+1];
		}
	}
	int l,r;
	for(int i=0;i<m;i++){
		scanf("%d %d",&l,&r);
		cout <<sum[l]-sum[r]+1<<endl;
	}
	return 0;
}