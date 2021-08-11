#include<bits/stdc++.h>
using namespace std;
int n,m,s;
const int inf=2147483647;
struct p{
	int from;
	int to;
	int val;//路的权值
	bool operator<(const p& b)const{
		return val<b.val;
	}
	bool operator>(const p& b)const{
		return val>b.val;
	}
};
vector<p>G[100004];
priority_queue<p,vector<p>,greater<p>>q;//小根堆
int ans[100004];
int main(){
	cin >>n>>m>>s;
	for(int i=1;i<=m;i++){//数据录入
		int from,to,val;
		scanf("%d %d %d",&from,&to,&val);
		G[from].push_back(p{from,to,val});
	}
	for(int i=1;i<=n;i++){
		ans[i]=inf;
	}
	ans[s]=0;
	q.push(p{s,s,0});
	while(!q.empty()){
		p out=q.top();q.pop();
		if(ans[out.to]!=inf&&ans[out.to]) continue;
		ans[out.to]=out.val;
		for(int i=0;i<(int)G[out.to].size();i++){
			if(ans[G[out.to][i].to]==inf){
				q.push(p{out.to,G[out.to][i].to,G[out.to][i].val+ans[out.to]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}