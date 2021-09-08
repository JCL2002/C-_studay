#include<bits/stdc++.h>
using namespace std;
struct ath{
	int i;
	int r[6];
};
ath arr[50005];
int n;
bool cmp(ath a,ath b){
	int na=0,nb=0;
	for(int i=1;i<=5;i++){
		if(a.r[i]<b.r[i])na++;
		else nb++;
	}
	return na>nb;
}
int main(){
	int t; cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++) cin >>arr[i].r[j];
			arr[i].i=i;
		}
		if(n==1){
			cout <<1<<endl;
			continue;
		}
		sort(arr+1,arr+1+n,cmp);
		bool flag=1;
		for(int i=2;i<=n;i++){
			if(!cmp(arr[1],arr[i])){
				flag=0;
				break;
			}
		}
		if(flag){
			cout <<arr[1].i<<endl;
		}
		else cout <<-1<<endl;
	}
	return 0;
}