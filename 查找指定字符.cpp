#include<stdio.h>
int main(){
	int inp,a[5],j=0;int carry=0;int div;
	scanf("%d",&inp);
	for(int i=4;i>=0;i--){
		carry=0;
		div=1;
		for(int k=0;k<i;k++){
			div*=10;
		}
		carry=inp/div;
		if (carry!=0){
			a[j]=carry;
			inp-=carry*div;
			j++;
		}
	}
	printf("back= ");
	carry=j;
	for(j--;j>=0;j--){
		printf("%d",a[j]); 
	}
	printf(",len=%d",carry);
}
