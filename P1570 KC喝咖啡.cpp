#include<bits/stdc++.h>
using namespace std;
int n,m;
struct flavour{
	int v;
	int c;
	double val;
};
flavour R[202];

bool cmp(flavour a,flavour b){
	return a.val<b.val;
}

bool test(double mid){
	for(int i=1;i<=n;i++){
		R[i].val=R[i].c*mid-R[i].v;
	}
	sort(R+1,R+1+n,cmp);
	double sum=0.0;
	for(int i=1;i<=m;i++){
		sum+=R[i].val;
	}
	if(sum<=0)return true;
	return false;
}

int main(){
	cin >>n>>m;
	double MIN=10000000,MAX=0,mid;
	for(int i=1;i<=n;i++){
		cin >>R[i].v;
	}
	for(int i=1;i<=n;i++){
		cin >>R[i].c;
	}
	for(int i=1;i<=n;i++){
		MIN=min(MIN,(double)R[i].v/R[i].c);
		MAX=max(MAX,(double)R[i].v/R[i].c);
	}
	mid=(MAX+MIN)/2;
	while(MAX-MIN>=0.0001){
		mid=(MAX+MIN)/2;
		if(test(mid)){
			MIN=mid;
		}
		else{
			MAX=mid;
		}
	}
	printf("%.3f",mid);
	return 0;
}