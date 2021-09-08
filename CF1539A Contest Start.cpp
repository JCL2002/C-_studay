#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >>t;
	while(t--){
		long long n,x,t;
		cin >>n>>x>>t;
		long long sum=0;
		long long time=t/x;
		sum+=min(time,n-1)*(min(time,n-1)+1)/2;
		if(n-time-1>0)sum+=(n-time-1)*time;
		cout <<sum<<endl;
	}
	return 0;
}