#include<bits/stdc++.h>
using namespace std;
int a;
int sum[1002][1002];
int s(int a,int b,int c,int d){
//	cout <<a <<' '<<b<<' '<<c <<' '<<d<<endl;
	return sum[c][d]+sum[a-1][b-1]-sum[a-1][d]-sum[c][b-1];
}
int main(){
	int n,m,c;
	cin >>n>>m>>c;
	c--;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+a-sum[i-1][j-1];
		}
	}
	int max=-900000000;//不可能比0还小
	int max_x,max_y;
	for(int i=1;i<=n-c;i++){
		for(int j=1;j<=m-c;j++){
			int tmp=s(i,j,i+c,j+c);
			if(tmp>max){
				max=tmp;
				max_x=i;
				max_y=j;
			}
		}
	}
	cout <<max_x <<' '<<max_y;
	return 0;
}