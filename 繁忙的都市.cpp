#include<bits/stdc++.h>
using namespace std;
const int N=304;
int n,m;
int fa[N];
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int Find(int x){
	if(x!=fa[x])fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	fa[ra]=rb;
}
struct e{
	int u;
	int v;
	int c;
};
bool cmp(e a,e b){
	return a.c<b.c;
}
e edge[100000];
int main(){
	cin >>n>>m;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].c);
	}
	sort(edge+1,edge+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(Find(edge[i].u)!=Find(edge[i].v)){
			ans=edge[i].c;
			Union(edge[i].u,edge[i].v);
		}
	}
	cout <<n-1<<' '<<ans;
	return 0;
}