#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[1003];
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
	int x;
	int y;
	int val;
};
e edge[10004];
bool cmp(e a,e b){
	return a.val<b.val;
}
int ans[1003];
int main(){
	cin >>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].val);
	}
	if(k>n){
		cout <<"No Answer";
		return 0;
	}
	sort(edge+1,edge+1+m,cmp);
	int sum=0;
	int num=0;
	for(int i=1;i<=m;i++){
		if(Find(edge[i].x)!=Find(edge[i].y)){
			sum+=edge[i].val;
			ans[++num]=sum;
			Union(edge[i].x,edge[i].y);
		}
	}
	cout <<ans[n-k];
	return 0;
}