#include<bits/stdc++.h>
using namespace std;
const int N=1003;
const int inf=2147483647;
int G[N][N];
int g[N][N];//反图
int arr[N];//到达所需时间
int back[N];//返回所需时间
int n,m;
void init(){
	for(int i=1;i<=n;i++){
		arr[i]=inf;
		back[i]=inf;
		for(int j=1;j<=n;j++){
			if(i==j){
				G[i][j]=0;
				g[i][j]=0;
			}
			else{
				G[i][j]=inf;
				g[i][j]=inf;
			}
		}
	}
}

struct point{
	int val;
	int i;
	bool operator< (const point& b)const{return val<b.val;}
	bool operator> (const point& b)const{return val>b.val;}
};
priority_queue<point,vector<point>,greater<point>> q;//小根堆
int main(){
	cin >>n >>m;
	init();
	for(int i=1;i<=m;i++){//录入
		int f,t,v;
		scanf("%d %d %d",&f,&t,&v);
		if(v<G[f][t])G[f][t]=v;
		if(v<g[t][f])g[t][f]=v;
	}
	//dijkstra算法
	q.push(point{0,1});
	while(!q.empty()){
		point out=q.top();q.pop();
		if(arr[out.i]!=inf)continue;
		arr[out.i]=out.val;
		for(int i=1;i<=n;i++){
			if(G[out.i][i]&&G[out.i][i]!=inf&&arr[i]==inf){
				q.push(point{out.val+G[out.i][i],i});
			}
		}
	}
	q.push(point{0,1});
	while(!q.empty()){
		point out=q.top();q.pop();
		if(back[out.i]!=inf)continue;
		back[out.i]=out.val;
		for(int i=1;i<=n;i++){
			if(g[out.i][i]&&g[out.i][i]!=inf&&back[i]==inf){
				q.push(point{out.val+g[out.i][i],i});
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=arr[i];
		sum+=back[i];
	}
	cout <<sum;
	return 0;
}