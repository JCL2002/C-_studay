#include<bits/stdc++.h>
using namespace std;
const int MAX=10000007;
int n;
bool vis[MAX];
int prime[MAX/2];
void cal(){
	int num=0;
	for(int i=2;i<=n;i++){
		if(!vis[i]) prime[++num]=i;
		for(int j=1;j<=num&&prime[j]*i<=n;j++){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0) break;
		}
	}
	
}
int main(){
	int t;
	cin >>t;
	n=MAX;
	cal();
	for(int i=1;i<=t;i++){
		cout <<prime[i]<<' ';
	}
	return 0;
}