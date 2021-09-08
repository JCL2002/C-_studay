#include<bits/stdc++.h>
using namespace std;
int fa[3001];
void init(){
	for(int i=1;i<=3000;i++)fa[i]=i;
}
int Find(int x){
	if(x!=fa[x]) fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	fa[ra]=rb;
}
struct edge{
	int u,v;
};
vector<edge>q;
int main(){
	init();
	int n,m1,m2;
	cin >> n >> m1>> m2;
	for(int i=0;i<m1;i++){
		int u,v;
		cin >>u>>v;
		Union(u,v);
	}
	for(int i=0;i<m2;i++){
		int u,v;
		cin >>u>>v;
		Union(u+1001,v+1001);
	}
	int mmax=max(n-m1,n-m2);
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(Find(i)!=Find(j)&&Find(i+1001)!=Find(j+1001)){
				num++;
				Union(i,j);
				Union(i+1001,j+1001);
				q.push_back({i,j});
				if(num==mmax){
					cout <<num<<endl;
					for(int k=0;k<num;k++){
						cout <<q[k].u<<" "<<q[k].v<<endl;
					}
					return 0;
				}
			}
		}
	}
	cout <<num<<endl;
	for(int i=0;i<num;i++){
		cout <<q[i].u<<" "<<q[i].v<<endl;
	}
}