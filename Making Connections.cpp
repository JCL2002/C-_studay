#include<bits/stdc++.h>
using namespace std;
#define int long long
long long gcd(long long a,long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}
struct node{
	int val;
	int father;
};
node fa[100005];
int n;
void init(){
	for(int i=1;i<=n;i++){
		fa[i].father=i;
		fa[i].val=1;
	}
}
node Find(int x){
	if(fa[x].father!=x) fa[x]=Find(fa[x].father);
	return fa[x];
}
void Union(int a,int b){
	node ra=Find(a),rb=Find(b);
	fa[ra.father].father=rb.father;
	fa[rb.father].val+=fa[ra.father].val;
}
signed main(){
	cin >>n;
	init();
	int m;
	cin >>m;
	long long sum=(long long)n;
	long long num=(long long)n;
	for(int i=1;i<=m;i++){
		int c;
		scanf("%lld",&c);
		if(c==2){//查询
			long long k=gcd(sum,num);
			cout <<sum/k<<"/"<<num/k<<endl;
		}
		else{
			int u,v;
			scanf("%lld %lld",&u,&v);
			node a=Find(u),b=Find(v);
			//把a并到b上；
			if(a.father!=b.father){
				sum-=a.val*a.val;
				sum-=b.val*b.val;
				Union(u,v);
				sum+=(a.val+b.val)*(a.val+b.val);
//				cout <<sum<<"  "<<(a.val+b.val)*(a.val+b.val)<<endl;
				num--;
			}
		}
	}
	return 0;
}