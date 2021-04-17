#include<stdio.h>
double ave(double a[],int n){
	double sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum/n;
}
int main(void)
{ 

 int N;

 scanf("%d",&N);

 double x[N],p;
 int i;
 for(i=0;i<N;i++)
  scanf("%lf",&x[i]);
 p=ave(x,N);
 printf("ave=%.2f\n",p);
 return 0;
}
