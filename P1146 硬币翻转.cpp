#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i%2){
				printf("0");
			}
			else{
				printf("1");
			}
		}
		for(int j=i+1;j<=n;j++){
			if(i%2){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		if(i<n){
			printf("\n");
		}
	}
	return 0;
}
