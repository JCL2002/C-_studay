#include<bits/stdc++.h>
using namespace std;
long long arr[200005];
priority_queue<long long,vector<long long>,greater<long long> >q;//Ð¡¸ù¶Ñ
int main(){
	int n;
	cin >>n;
	for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
	long long sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum+=arr[i];
		if(arr[i]<0) q.push(arr[i]);
		if(sum<0){
			sum-=q.top();
			q.pop();
			ans--;
		}
		ans++;
	}
	cout <<ans;
	return 0;
}