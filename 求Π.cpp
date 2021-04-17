#include<stdio.h>
int main(){
	double a=1.0/3,val=1.0;
	for(int b=3,c=-1;;b+=2,c*=-1){
		a=1.0/b;
		if(a>=0.000001) val+=c*a;
		else break;
	}
	val*=4.0;
	printf("%.6f",val);
	return 0;
}
