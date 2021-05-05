#include<bits/stdc++.h>
using namespace std;
unsigned int n,p;
unsigned long long inv[3000001];
int main(){
	cin >>n>>p;
	inv[1]=1;
	for(int i=2;i<=(int)n;i++){
		inv[i]=p-p/i*inv[p%i]%p;
	}
	for(int i=1;i<=(int)n;i++){
		printf("%d\n",inv[i]);
	}
	return 0;
}