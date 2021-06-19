#include <bits/stdc++.h>
using namespace std;
//二维数组前缀和
int n,m;
int sum[102][102];
int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int tmp;
			scanf("%d",&tmp);
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+tmp;
		}
	}
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int possible=sqrt(sum[i][j]);//最大可能的正方形是当前的sum值开根号，不可能有比他还大的正方形
			possible=min(possible,min(i,j));//正方形的大小不可能超过i，j中的最小值，这是为了防止下标越界
			for(int k=possible;k>0;k--){
				if(k*k==sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k]){
					if(k>max){
						max=k;
						break;
					}
					else{
						break;
					}
				}
			}
		}
	}
	cout <<max;
	return 0;
}