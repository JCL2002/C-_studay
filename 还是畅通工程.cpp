#include<bits/stdc++.h>
using namespace std;
const int N=103;
const int M=10005;
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
	int val;
};
e edge[M];
bool cmp(e a ,e b){
	return a.val<b.val;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		init();
		for(int i=1;i<=n*(n-1)/2;i++){
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].val);
		}
		sort(edge+1,edge+1+n*(n-1)/2,cmp);
		long long sum=0;
		for(int i=1;i<=n*(n-1)/2;i++){
			if(Find(edge[i].u)!=Find(edge[i].v)){
				sum+=edge[i].val;
				Union(edge[i].u,edge[i].v);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}