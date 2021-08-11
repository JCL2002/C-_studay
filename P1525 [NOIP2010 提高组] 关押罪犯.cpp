#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[40006];
void init(){
	for(int i=0;i<=2*n+2;i++){
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
struct cri{
	int i;
	int j;
	int c;
};
cri arr[100005];
bool cmp(cri a,cri b){
	return a.c>b.c;
}
int main(){
	cin >>n>>m;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&arr[i].i,&arr[i].j,&arr[i].c);
	}
	sort(arr+1,arr+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(Find(arr[i].i)==Find(arr[i].j)){
			cout <<arr[i].c;
			return 0;
		}
		Union(n+arr[i].i,arr[i].j);
		Union(n+arr[i].j,arr[i].i);
	}
	cout <<0;
	return 0;
}
//敌人的敌人，就是朋友