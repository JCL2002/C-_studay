#include<bits/stdc++.h>
using namespace std;
int inital[100005];
int sorted[100005];
int arr[100005];
int n;
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		int mmax=0;
		int mmin=100005;
		for(int i=1;i<=n;i++){
			cin >>arr[i];
			mmax=max(mmax,arr[i]);
			mmin=min(mmin,arr[i]);
		}
		for(int i=mmin;i<=mmax;i++)inital[i]=sorted[i]=0;
		for(int i=1;i<=n;i++) {
			if(i%2){
				inital[arr[i]]++;
			}
		}
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++){
			if(i%2){
				sorted[arr[i]]++;
			}
		}
		bool flag=1;
		for(int i=mmin;i<=mmax;i++){
			if(inital[i]!=sorted[i]){
				flag=0;
				break;
			}
		}
		if(flag)cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
	}
}