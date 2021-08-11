#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[1009];
void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
}
int Find(int x){
	if(x!=fa[x]) fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	fa[ra]=rb;
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n>>m;
		init();
		for(int i=1;i<=m;i++){
			int a,b;cin >>a>>b;
			Union(a,b);
		}
		int num=0;
		for(int i=1;i<=n;i++){
			if(fa[i]==i)num++;
		}
		cout <<num<<endl;
	}
	return 0;
}