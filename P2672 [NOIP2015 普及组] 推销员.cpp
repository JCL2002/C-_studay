#include<bits/stdc++.h>
using namespace std;
struct Node{
	int distance;
	int tire;
};
Node arr[100002];
long long sum[100002];//0-i-1tire的求和
int max_of_distance[100002];//前i大的最大距离
long long behind[100002];//从i到n路径加权最大值
bool cmp(Node a,Node b){
	return a.tire>b.tire;
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i].distance);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i].tire);
	}
	sort(arr+1,arr+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i].tire;
	}
	for(int i=1;i<=n;i++){
		max_of_distance[i]=max(max_of_distance[i-1],arr[i].distance);
	}
	for(int i=n;i>0;i--){
		behind[i]=max(behind[i+1],(long long)2*arr[i].distance+arr[i].tire);
	}
	for(int i=1;i<=n;i++){
		printf("%lld\n",max(sum[i-1]+behind[i],sum[i]+2*max_of_distance[i]));
	}
	return 0;
}