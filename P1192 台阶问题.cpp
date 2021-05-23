#include<bits/stdc++.h>
using namespace std;
int arr[100001];

int n,k;
int main(){
	arr[0]=1;
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		int sum=0;
		if(i<=k){
			for(int j=0;j<i;j++){
				sum=(sum+arr[j])%100003;
			}
		}
		else{
			for(int j=k;j>0;j--){
				sum=(sum+arr[i-j])%100003;
			}
		}
		arr[i]=sum;
	}
	cout <<arr[n];
	return 0;
}