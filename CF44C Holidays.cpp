#include<bits/stdc++.h>
using namespace std;
int l[102];
int main(){
	int n,m;
	cin >>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		l[a]++;
		l[b+1]--;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=l[i];
		if(sum>1||sum==0){
			printf("%d %d",i,sum);
			return 0;
		}
	}
	printf("OK");
	return 0;
}