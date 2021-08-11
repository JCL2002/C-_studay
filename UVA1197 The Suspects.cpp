#include<iostream>
using namespace std;
int n,m;
int fa[30003];
void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
}
int Find(int x){//²¢²é¼¯-find
	if(x!=fa[x]){
		fa[x]=Find(fa[x]);
	}
	return fa[x];
}
void Union(int a,int b){
	int af=Find(a),bf=Find(b);
	if(af==bf)return;
	fa[af]=bf;
}

int main(){
	while(true){
		cin >>n>>m;
		if(n==0&&m==0)break;
		init();
		for(int i=1;i<=m;i++){
			int k,f;
			scanf("%d %d",&k,&f);
			for(int j=2;j<=k;j++){
				int s;
				scanf("%d",&s);
				Union(f,s);
			}
		}
		int target=Find(0);
		int num=0;
		for(int i=1;i<=n;i++){
			if(target==Find(i))num++;
		}
		cout <<num+1<<endl;
	}
	return 0;
}