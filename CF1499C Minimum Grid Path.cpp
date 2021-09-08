#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q1;//小根堆，记录水平方向上最小值
priority_queue<int,vector<int>,greater<int> >q2;//小根堆，记录垂直方向上最小值
int n;
int c[100005];
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++) cin >> c[i];
		long long ans=1e18+7;
		long long sum_h=0;
		long long sum_v=0;
		for(int i=1;i<=n;i++){
			if(i&1){
				sum_h+=c[i];
				q1.push(c[i]);
			}
			else{
				sum_v+=c[i];
				q2.push(c[i]);
			}
			long long h=0,v=0;
			if(i>1){
				h=sum_h+(long long)q1.top()*(long long)(n-(i+1)/2);
				v=sum_v+(long long)q2.top()*(long long)(n-i/2);
				ans=min(ans,h+v);
			}
		}
		cout <<ans<<endl;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
	}
	return 0;
}