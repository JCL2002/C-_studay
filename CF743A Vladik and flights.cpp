#include<bits/stdc++.h>
using namespace std;
char ar[100001];
int main(){
	int n,a,b;
	cin >>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin >>ar[i];
	}
	if(ar[a]==ar[b]){
		printf("0");return 0;
	}
	else{
		cout <<'1';
	}
	return 0;
}