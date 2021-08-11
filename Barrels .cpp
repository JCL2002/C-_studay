#include<bits/stdc++.h>
using namespace std;
long long arr[300006];
bool cmp(long long  a,long long b){
	return a>b;
}
int main(){
	int t;cin >>t;
	while(t--){
		int n;int k;cin >>n>>k;
		for(int i=1;i<=n;i++){
			scanf("%lld",arr+i);
		}
		sort(arr+1,arr+1+n,cmp);
		long long sum=0;
		for(int i=1;i<=k+1;i++) sum+=arr[i];
		cout <<sum<<endl;
	}
	return 0;
}