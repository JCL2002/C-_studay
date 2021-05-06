#include<bits/stdc++.h>
using namespace std;
int main(){
	char str[1001];
	cin >>str;
	long long list[1001];
	for(int i=0;i<1001;i++){//数组初始化
		list[i]=0;
	}
	for(int i=0;i<(int)strlen(str);i++){
		list[i+1]=list[i]+str[i];
	}
	int n;
	cin >>n;
	int l,r;
	for(int i=0;i<n;i++){
		scanf("%d %d",&l,&r);
		printf("%lld\n",list[r]-list[l-1]);
	}
	return 0;
}