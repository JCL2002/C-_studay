#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main(){
	int t,n;cin >>t;
	for(int i=0;i<t;i++){
		cin >>n;if(n==2) {
			printf("-1\n");
			continue;
		}
		else if(n==1) {
			printf("1\n");
			continue;
		}
		else{
			int number=-n+1;
			for(int j=0;j<n-1;j++){
				for(int k=1;k+j<=n;k++){
					a[k+j][k]=number;number++;
				}
				for(int k=1;k+j<=n;k++){
					a[k][k+j]=number;number++;
				}
			}
			a[n][1]=number;number++;a[1][n]=number;
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				printf("%d",a[j][k]);
				if(k!=n){
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}