#include<bits/stdc++.h>
using namespace std;
int MAP[2][1000006];
int sum[2][1000006];//后缀和
int m;
int main(){
	int t;cin >>t;
	while(t--){
		cin >>m;
		for(int i=1;i<=m;i++){
			scanf("%d",&MAP[0][i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&MAP[1][i]);
		}
		MAP[0][1]=0;
		MAP[1][m]=0;
		sum[0][m+1]=0;
		sum[1][m+1]=0;
		for(int i=m;i>0;i--){
			sum[0][i]=sum[0][i+1]+MAP[0][i];
			sum[1][i]=sum[1][i+1]+MAP[1][i];
		}
//		sum[0][1]=0;sum[1][m]=0;
//		cout <<sum[0][1]<<"  "<<sum[1][1]<<endl;
		int MIN=max(sum[0][1],sum[1][1]);
//		cout <<endl<<MIN<<endl<<endl;
		for(int i=1;i<=m;i++){//Alice从第i处下去
			MIN=min(MIN,max(sum[0][i+1],sum[1][1]-sum[1][i]));
		}
		cout <<MIN<<endl;
	}
	return 0;
}