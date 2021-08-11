#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
int arr[10005];//并查集
struct road{
	int u;
	int v;
	int w;
};
road R[200005];
void init(){//并查集的初始化
	for(int i=1;i<=n;i++){
		arr[i]=i;
	}
}

int find(int a){//并查集-find
	if(a==arr[a]) return a;
	else return arr[a]=find(arr[a]);
}

void Union(int a,int b){//并查集-union
	int r_a=find(a),r_b=find(b);
	if(r_a!=r_b){
		arr[r_a]=r_b;
	}
}

bool test(int mid){
	init();
	for(int i=1;i<=m;i++){
		if(R[i].w<=mid){
			Union(R[i].u,R[i].v);
		}
	}
	if(find(s)==find(t)) return true;
	return false;
}
int main(){
	cin >>n>>m>>s>>t;
	int MIN=9000000,MAX=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&R[i].u,&R[i].v,&R[i].w);
		MIN=min(R[i].w,MIN);
		MAX=max(R[i].w,MAX);
	}
	int mid=(MIN+MAX)/2;
	while(MIN<MAX){
		if(MAX-MIN==1){
			if(test(MIN)){
				mid=MIN;
				break;
			}
			else{
				mid=MAX;
				break;
			}
		}
		mid=(MIN+MAX)/2;
		if(test(mid)){
			MAX=mid;
		}
		else{
			MIN=mid;
		}
	}
	cout <<mid<<endl;
	return 0;
}