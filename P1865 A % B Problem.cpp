#include<bits/stdc++.h>
using namespace std;
bool vis[1000006];
int prime[500005];
int arr[1000006];//从1-i质数的个数
int n,m;
int main(){
	cin >>n>>m;
	int num=0;
	for(int i=2;i<=m;i++){
		if(!vis[i])prime[++num]=i;
		arr[i]=num;
		for(int j=1;j<=num&&prime[j]*i<=m;j++){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=0;i<n;i++){
		long long l,r;
		cin >>l>>r;
		if((long long)m<r||l<1||r<1){
			cout <<"Crossing the line"<<endl;
			continue;
		}
		cout <<arr[r]-arr[l-1]<<endl;
	}
	return 0;
}