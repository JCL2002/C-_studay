#include<stdio.h>
int main(){
	float p,w,f;int s;
	scanf("%f %f %d",&p,&w,&s);
	if(s<250) f=p*w*s;
	else if(s<500) f=p*w*s*0.98;
	else if(s<1000) f=p*w*s*0.95;
	else if(s<2000) f=p*w*s*0.92;
	else if(s<3000) f=p*w*s*0.9;
	else f=p*w*s*0.85;
	printf("%.4f",f);
}
