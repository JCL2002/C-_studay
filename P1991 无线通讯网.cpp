#include<bits/stdc++.h>
using namespace std;
const int N = 125005;
struct point{//哨所的坐标
	int id;//哨所id，用作并查集
	int x;
	int y;
};
point P[505];
struct e{
	int a;//哨所a的id
	int b;//哨所b的id
	float distance;//两个哨所之间的距离
};
e edge[N];
bool cmp(e a,e b){
	return a.distance<b.distance;
}
int n,m;
int fa[N];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int Find(int x){
	if(x!=fa[x])fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	fa[ra]=rb;
}
float choosen[N];//被选中的边
int noc;//被选中的个数(number of choosen)
int main(){
	cin >>m>>n;
	init();
	for(int i=1;i<=n;i++){//数据录入
		scanf("%d %d",&P[i].x,&P[i].y);
		P[i].id=i;
	}
	//计算每个哨所到其他哨所的距离
	int number=1;//边的数量=n*(n+1)/2
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			edge[++number].a=P[i].id;
			edge[number].b=P[j].id;
			edge[number].distance=sqrt((float)(P[i].x-P[j].x)*(P[i].x-P[j].x)+(float)(P[i].y-P[j].y)*(P[i].y-P[j].y));
		}
	}
	sort(edge+1,edge+1+number,cmp);
	for(int i=1;i<=number;i++){
		if(Find(edge[i].a)!=Find(edge[i].b)){
			choosen[noc++]=edge[i].distance;
			Union(edge[i].a,edge[i].b);
		}
	}
	printf("%.2f",choosen[noc-m]);
	return 0;
}