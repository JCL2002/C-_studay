#include<stdio.h>
int main(){
	int i,j,h;
	for (i=1;i<=1000;i++){
		h=i;
		for (j=1;j<i;j++){
			if(i%j==0) h-=j;
		}
		if (h==0) {
			printf("%d:",i);
			for (j=1;j<i;j++){
				if(i%j==0) printf(" %d",j);
			}
			printf("\n");
		}
	}
	return 0;
}
