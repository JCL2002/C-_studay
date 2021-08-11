#include<bits/stdc++.h>
using namespace std;
int fa[5005];
long long sum;//长度总和
//并查集

int n,m;
int Find(int x){
	if(x!=fa[x]) fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	fa[ra]=rb;
}
struct p{
	int l;
	int r;
	int len;
};
p point[200005];
bool cmp(p a,p b){
	return a.len<b.len;
}
void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
}

int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&point[i].l,&point[i].r,&point[i].len);
	}
	sort(point+1,point+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(Find(point[i].l)!=Find(point[i].r)){
			Union(point[i].l,point[i].r);
			sum+=point[i].len;
		}
	}
	int flag=Find(1);
	bool t=true;
	for(int i=2;i<=n;i++){
		if(Find(i)!=flag){
			t=false;
			break;
		}
	}
	if(t){
		cout <<sum;
	}
	else{
		cout <<"orz";
	}
	return 0;
}