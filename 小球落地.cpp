#include<stdio.h>
int main(){
	int n;double distance,a=1.0,hight=100.0;
	scanf("%d",&n);
	if (n==1) {
		distance=100.0;
		hight=50.0;
	}
	else {
		for(int i=1;i<n-1;i++){
			a/=2.0;
		}
		a=2.0-a;
		distance=100.0+100*a;
		for(int i=1;i<=n;i++){
			hight/=2.0;
		}
	}
	printf("%.4f\n%.4f\n",distance,hight);
	return 0;
} 
