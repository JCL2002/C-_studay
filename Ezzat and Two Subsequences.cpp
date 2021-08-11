#include<bits/stdc++.h>
using namespace std;
const int  N=100005;
long long arr[N];
int main(){
	int t;cin >>t;
	while(t--){
		int n;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>arr[i];
		}
		sort(arr+1,arr+1+n);
		long long max=arr[n];
		long long sum=0;
		for(int i=1;i<n;i++) sum+=arr[i];
		double a=(double)max,b=(double)sum/(n-1);
		printf("%.9f\n",a+b);
	}
	
	return 0;
}