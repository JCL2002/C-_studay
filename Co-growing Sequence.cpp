#include<iostream>
using namespace std;
int x[200005];
int cache[200005];
int main(){
	int t;cin >>t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",x+i);
		}
		//bool flag=true;
		cache[1]=x[1];
		for(int i=2;i<=n;i++){
			cache[i]=cache[i-1]|x[i];
		}
	
		for(int i=1;i<=n;i++){
			printf("%d ",cache[i]^x[i]);
		}
		printf("\n");
	}
	return 0;
}