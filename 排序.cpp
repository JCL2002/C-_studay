#include<stdio.h>
int main(){
	float a,b,c,max,med,min;
	scanf("%f %f %f",&a,&b,&c);
	if(a>b) {
		if (a>c) {
			max=a;
			if (b>c) {med=b;min=c;}else {med=c;min=b;}
		}
		else {max=c;med=a;min=c;}}
	else {
		if(b>c) {
			max=b;if(a>c) {med=a;min=c;}else {med=c;min=a;}
		}
		else {max=c;med=b;min=a;}
	}
	printf("%.2f %.2f %.2f",min,med,max);
	return 0;
}
