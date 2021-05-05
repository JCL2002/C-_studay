#include<bits/stdc++.h>
using namespace std;
int l[1002][1002];
int main(){
	int n,m;
	cin >>n >>m;
	int a,b,c,d;
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		//两个端点做标记
		l[a][b]++;
		l[a][d+1]--;
		for(int j=a+1;j<=c;j++){
			l[j][b]++;
			l[j][d+1]--;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=l[i][j];
			printf("%d",sum);
			if(j!=n){
				printf(" ");
			}
		}
		sum=0;
		printf("\n");
	}
	return 0;
}