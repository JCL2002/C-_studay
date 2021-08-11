#include<bits/stdc++.h>
using namespace std;
const int N=4000009;
const long long mod=998244353;
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
bool res[8000008];
int main(){
	cin >>n>>m;
	init();
	int num=0;
	for(int i=1;i<=m;i++){
		int op;int u,v;
		scanf("%d %d %d",&op,&u,&v);
		if(op==0){
			
			Union(u,v);
		}
		else{
			if(Find(u)==Find(v))res[++num]=1;
			else res[++num]=0;
		}
	}
	long long sum=0;
	long long base=1;
	for(int i=num;i>0;i--){
		if(res[i]){
			sum=(sum%mod+base%mod)%mod;
		}
		base=((base%mod)*2)%mod;
	}
	cout <<sum;
	return 0;
}