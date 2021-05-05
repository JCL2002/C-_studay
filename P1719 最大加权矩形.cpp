#include<bits/stdc++.h>
using namespace std;
short int a[122][122];
int sum[122][122];
int built(int x,int y,int n){
	int max=-90000000;
	for(int i=x;i<=n;i++){
		for(int j=y;j<=n;j++){
			if(i==x||j==y){//第一行或者第一列
				if(i==x&&j==y){//起点
					sum[i][j]=a[i][j];
				}
				else if(i==x){//第一行
					sum[i][j]=sum[i][j-1]+a[i][j];
				}
				else{//第一列
					sum[i][j]=sum[i-1][j]+a[i][j];
				}
			}
			else{
				sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
			if(sum[i][j]>max){
				max=sum[i][j];
			}
		}
	}
	return max;
}
int main(){
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%hd",&a[i][j]);
		}
	}
	int max=-900000000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int tmp=built(i,j,n);
			if(tmp>max) max=tmp;
		}
	}
	cout <<max;
	return 0;
}