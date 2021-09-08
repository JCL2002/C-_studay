#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int dp[100005];
int D[100005];
int n;
int main(){
	while(cin>>arr[++n]);
	n--;
	for(int i=1;i<=n;i++){
		int mmax=0;
		for(int j=1;j<i;j++){
			if(arr[j]>=arr[i]){
				mmax=max(dp[j],mmax);
			}
		}
		dp[i]=mmax+1;
	}
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=1;j<i;j++){
			if(arr[j]<arr[i]){
				num=max(D[j],num);
			}
		}
		D[i]=num+1;
	}
	int mmax=0;
	int num=0;
	for(int i=1;i<=n;i++){
		num=max(num,D[i]);
		mmax=max(mmax,dp[i]);
	}
	cout << mmax << endl;
	cout << num;
	return 0;
}