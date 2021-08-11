#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[100005];
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int Find(int x){
	if(x!=fa[x]) fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	fa[ra]=rb;
}
struct e{
	int u;
	int v;
	int w;
};
bool cmp(e a,e b){
	return a.w>b.w;
}
e edge[100005];
int main(){
	cin >>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	sort(edge+1,edge+1+m,cmp);
	long long sum=0;
	int num=0;
	for(int i=1;i<=m;i++){
		if(Find(edge[i].u)!=Find(edge[i].v)){
			sum+=edge[i].w;
			Union(edge[i].u,edge[i].v);
			num++;
			if(num==k) break;
		}
	}
	cout <<sum;
	return 0;
}