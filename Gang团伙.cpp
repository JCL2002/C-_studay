#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[2006];
void init(){
	for(int i=0;i<=2*n+2;i++){
		fa[i]=i;
	}
}

int Find(int x){
	if(x!=fa[x]){
		fa[x]=Find(fa[x]);
	}
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	if(ra==rb) return;
	fa[ra]=rb;
}

int main(){
	cin >>n>>m;
	init();
	char p;int x,y;
	for(int i=1;i<=m;i++){
		cin >>p>>x>>y;
		if(p=='F'){
			Union(x,y);
		}
		else{
			Union(x+n,y);
			Union(y+n,x);
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i)num++;
	}
	cout <<num<<endl;
	return 0;
}