#include<stdio.h>
int main(){
	int inp,a[5],div,count;
	scanf("%d",&inp);
	for(int i=4;i>=0;i--){
		div=1;
		for(int j=0;j<i;j++){
			div*=10;
		}
		a[(4-i)]=inp/div;
		inp-=a[(4-i)]*div;
	}
	for(int i=0;i<5;i++){
		if (a[i]!=0) {
		count=(5-i);
		break;
		}
	}
	printf("%d\n",count);
	for (int i=(5-count);i<5;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=4;i>=(5-count);i--){
		printf("%d ",a[i]);
	}
	return 0;
}
