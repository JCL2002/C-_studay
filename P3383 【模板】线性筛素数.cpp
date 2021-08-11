#include<bits/stdc++.h>
using namespace std;
bool vis[100000008];
int prime[50000007];
int main(){
	int n,q;
	cin >>n>>q;
	int num=0;
	for(int i=2;i<=n;i++){
		if(!vis[i]) prime[++num]=i;
		for(int j=1;j<=num&&prime[j]*i<=n;j++){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=0;i<q;i++){
		int tmp;
		scanf("%d",&tmp);
		printf("%d\n",prime[tmp]);
	}
	return 0;
}