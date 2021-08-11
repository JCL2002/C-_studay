#include<bits/stdc++.h>
using namespace std;
int A,B;
int fa[505];
void init(){
	for(int i=1;i<=B;i++)fa[i]=i;
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
e edge[250005];
bool cmp(e a,e b){
	return a.val<b.val;
}
int main(){
	cin >>A>>B;
	init();
	int num=0;
	for(int i=1;i<=B;i++){
		for(int j=1;j<=B;j++){
			scanf("%d",&edge[++num].val);
			edge[num].x=i;edge[num].y=j;
			if(edge[num].val==0)edge[num].val=A;
			if(edge[num].val>A)edge[num].val=A;
		}
	}
	sort(edge+1,edge+1+num,cmp);
	long long sum=A;
	for(int i=1;i<=num;i++){
		if(Find(edge[i].x)!=Find(edge[i].y)){
			sum+=edge[i].val;
			Union(edge[i].x,edge[i].y);
		}
	}
	cout <<sum;
	return 0;
}