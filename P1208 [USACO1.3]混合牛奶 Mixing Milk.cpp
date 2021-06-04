#include<bits/stdc++.h>
using namespace std;
struct O{
	int val;
	int num;
};
O arr[5001];
bool cmp(O a,O b){
	return a.val<b.val;
}
int main(){
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&arr[i].val,&arr[i].num);
	}
	sort(arr+1,arr+m+1,cmp);
	int money=0,weight=0;
	int i=1;
	while(weight<n){
		if(arr[i].num>n-weight){
			money+=(n-weight)*arr[i].val;
			weight=n;
			continue;
		}
		money+=arr[i].val*arr[i].num;
		weight+=arr[i].num;
		i++;
	}
	cout <<money;
	return 0;
}