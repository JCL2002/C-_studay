#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[1003];
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
struct p{
	int x;
	int y;
};
p position[1003];
struct e{
	int u;
	int v;
	double distance;
};
e edge[700006];
bool cmp(e a,e b){
	return a.distance<b.distance;
}
int main(){
	cin >>n>>m;
	init();
	for(int i=1;i<=n;i++){
		scanf("%d %d",&position[i].x,&position[i].y);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		Union(u,v);
	}
	//计算每个边的长度
	int num=0;
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			edge[++num].u=i;edge[num].v=j;
			edge[num].distance=sqrt((double)(position[edge[num].u].x-position[edge[num].v].x)*(position[edge[num].u].x-position[edge[num].v].x)+(double)(position[edge[num].u].y-position[edge[num].v].y)*(position[edge[num].u].y-position[edge[num].v].y));
		}
	}
	sort(edge+1,edge+1+num,cmp);
	double sum=0.0;
	for(int i=1;i<=num;i++){
		if(Find(edge[i].u)!=Find(edge[i].v)){
			sum+=edge[i].distance;
			Union(edge[i].u,edge[i].v);
		}
	}
	printf("%.2f",sum);
	return 0;
}