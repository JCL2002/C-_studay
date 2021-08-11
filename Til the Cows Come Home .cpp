#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
const int inf=2147483647;
int t,n;
int ans[1003];
void init(){
	for(int i=1;i<=n;i++)ans[i]=inf;
}
struct p{
	int n;
	int val;
	bool operator>(const p& b)const{return val>b.val;}
};
vector<p>G[1003];//ÁÚ½Ó±í´æÍ¼

priority_queue< p,vector<p>,greater<p> >q;
int main(){
	cin >>t>>n;
	init();
	for(int i=1;i<=t;i++){
		int from,to,val;
		scanf("%d %d %d",&from,&to,&val);
		G[from].push_back(p{to,val});
		G[to].push_back(p{from,val});
	}
	q.push(p{n,0});
	while(!q.empty()){
		p out=q.top();q.pop();
		if(ans[out.n]!=inf)continue;
		ans[out.n]=out.val;
		for(int i=0;i<(int)G[out.n].size();i++){
			if(ans[G[out.n][i].n]==inf){
				q.push(p{G[out.n][i].n,ans[out.n]+G[out.n][i].val});
			}
		}
	}
	cout <<ans[1];
	return 0;
}