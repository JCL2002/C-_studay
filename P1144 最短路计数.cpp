#include<bits/stdc++.h>
using namespace std;
const int N=1000006;
int ans[N];
int dep[N];
bool vis[N];
vector<int>G[N];//ÁÚ½Ó±í´æÍ¼
queue<int>q;
int n,m;
int main(){
	cin >>n>>m;
	for(int i=1;i<=m;i++){
		int from,to;
		scanf("%d %d",&from,&to);
		G[from].push_back(to);
		G[to].push_back(from);
	}
	for(int i=1;i<=n;i++){
		dep[i]=N;
	}
	q.push(1);
	ans[1]=1;dep[1]=1;
	while(!q.empty()){
		int out=q.front();q.pop();
		if(vis[out])continue;
		vis[out]=1;
		for(int i=0;i<(int)G[out].size();i++){
			if(dep[G[out][i]]>dep[out]&&vis[G[out][i]]==0){
				ans[G[out][i]]=(ans[out]+ans[G[out][i]])%100003;
				dep[G[out][i]]=dep[out]+1;
				q.push(G[out][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}