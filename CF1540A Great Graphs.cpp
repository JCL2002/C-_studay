#include<bits/stdc++.h>
using namespace std;
int arr[100005];
long long go;//去的总路程
long long back;//回来的总路程
long long sum;//前缀和数组
int main(){
	int t;cin >>t;
	while(t--){
		go=0;back=0;sum=0;
		int n;cin >>n;
		for(int i=1;i<=n;i++) cin >> arr[i];
		sort(arr+1,arr+1+n);
		for(int i=2;i<=n;i++){
			go+=arr[i]-arr[i-1];
		}
		for(int i=n-1;i>0;i--){
			sum+=arr[i+1];
			back+=((long long)arr[i]*(n-i)-sum);
		}
		cout <<go+back<<endl;
	}
	return 0;
}