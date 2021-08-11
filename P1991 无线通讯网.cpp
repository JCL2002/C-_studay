#include<bits/stdc++.h>
using namespace std;
const int N = 125005;
struct point{//����������
	int id;//����id���������鼯
	int x;
	int y;
};
point P[505];
struct e{
	int a;//����a��id
	int b;//����b��id
	float distance;//��������֮��ľ���
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
float choosen[N];//��ѡ�еı�
int noc;//��ѡ�еĸ���(number of choosen)
int main(){
	cin >>m>>n;
	init();
	for(int i=1;i<=n;i++){//����¼��
		scanf("%d %d",&P[i].x,&P[i].y);
		P[i].id=i;
	}
	//����ÿ�����������������ľ���
	int number=1;//�ߵ�����=n*(n+1)/2
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