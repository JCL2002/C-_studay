#include<stdio.h>
int main(){
	int i,j,k,a,fenzi=1,fenmu=1;
	scanf("%d",&a);
	//i代表当前行
	//j代表当前行的当前个元素 
	for(i=1;i<=a;i++){
		for(j=1;j<=i;j++){
			if ((i==1)or(j==1)or(j==i)) printf("1 ");
			else{
				for(k=(i-1),fenzi=1;k>=(i-j+1);k--){
					fenzi*=k;
				}
				for(k=1,fenmu=1;k<j;k++){
					fenmu*=k;
				}
				int lsp;lsp=fenzi/fenmu;
				printf("%d ",lsp);
			}
		}
		printf("\n");
	}
	return 0;
}
