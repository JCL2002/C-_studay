#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,k;
int Log[100001];
int ac(int n){//求n能解出多少题目
	long long sum=0;
	int k=0;
	for(int i=1;i<=l;i++){
		sum+=Log[i];
		if(sum>=n){
			k++;
			sum=0;
		}
		else if(sum<0){
			sum=0;
		}
	}
	return k;
}
signed main(){
	cin >>l>>k;
	for(int i=1;i<=l;i++){
		scanf("%lld",Log+i);
	}
	long long min=-1,max=-1;
	long long l=1;long long r=9000000000000;
	while(l<=r){//求最小
		long long mid=(l+r)/2;
		long long tmp=ac(mid);
		if(tmp<=k){
			if(tmp==k){
				min=mid;
			}
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	l=1;r=9000000000000;
	while(l<=r){
		long long mid=(l+r)/2;
		long long tmp=ac(mid);
		if(tmp>=k){
			if(tmp==k){
				max=mid;
			}
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if(min>0&&max>0){
		cout <<min <<' '<<max;
	}
	else{
		cout <<-1;
	}
	return 0;
}