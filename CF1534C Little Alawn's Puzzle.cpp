#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int fa[400005];
int Find(int x){
	if(x!=fa[x]) fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	fa[ra]=rb;
}
long long power(long long x,int n){
	long long res=1;
	while(n){
		if(n&1) res=(res*x)%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return res;
}
int n;
void init(){
	for(int i=1;i<=n;i++)fa[i]= i;
}
int arr[400005];
int brr[400005];
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		init();
		for(int i=1;i<=n;i++) cin >> arr[i];
		for(int i=1;i<=n;i++) cin >> brr[i];
		for(int i=1;i<=n;i++) Union(arr[i],brr[i]);
		int num=0;
		for(int i=1;i<=n;i++){
			if(Find(i)==i)num++;
		}
		cout <<power(2ll,num)<<endl;
	}
	return 0;
}