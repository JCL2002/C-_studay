#include<iostream>
using namespace std;
long long x;
long long dfs(int depth,long long k){//0代表找不到
	if(depth>19) return 0;
	if(k%x==0) return k;
	long long t1,t2;
	t1=dfs(depth+1,k*10);
	t2=dfs(depth+1,k*10+1);
	if(t1) return t1;
	if(t2) return t2;
	return 0;
}

int main(){
	while(true){
		cin >>x;
		if(x==0) break;
		printf("%lld\n",dfs(1,x));
		
	}
	
	
	
	return 0;
}