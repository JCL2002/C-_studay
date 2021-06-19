#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a;
	int b;
};
Node arr[20012];
long long c,sum;
bool cmp(Node a,Node b){//排序规则
	int d1=(a.a-a.b);
	int d2=(b.a-b.b);
	if(d1){
		d1/=abs(d1);
	}
	if(d2){
		d2/=abs(d2);
	}
	if(d1!=d2){
		return d1<d2;
	}
	if(d1<=0){
		return a.a<b.a;
	}
	return a.b>b.b;
}
int main(){
	int t;
	cin >>t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&arr[i].a,&arr[i].b);
		}
		sort(arr+1,arr+1+n,cmp);//按min(ai,bj)<max(aj,bi)不需交换的规则排序
		sum=0ll;c=0ll;
		for(int i=1;i<=n;i++){
			sum+=arr[i].a;
			c=max(c,sum)+arr[i].b;//递推c
		}
		printf("%lld\n",c);
	}
	return 0;
}