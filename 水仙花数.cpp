#include<stdio.h>
int main(){
	int a1,a2,a3;
	for(int i=100;i<=999;i++){
	
	a1=i/100;a2=(i-a1*100)/10;a3=i-a1*100-a2*10;
	if (a1*a1*a1+a2*a2*a2+a3*a3*a3==i) printf("%d\n",i);
	}
	return 0;
}
