#include<bits/stdc++.h>
using namespace std;
struct po{
	long long p;
	bool a;
};
po arr[400005];
long long num[200005];
bool cmp(po a,po b){
	return a.p<b.p;
}
int main(){
	int n;cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&arr[2*i-1].p,&arr[2*i].p);
		arr[2*i-1].a=1;arr[2*i].a=0;
		arr[2*i].p++;
	}
	sort(arr+1,arr+1+2*n,cmp);
	int hight=0;long long left=0;
	for(int i=1;i<=2*n;i++){
		num[hight]+=arr[i].p-left;
		if(arr[i].a){
			hight++;
		}
		else{
			hight--;
		}
		left=arr[i].p;
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",num[i]);
	}
	return 0;
}