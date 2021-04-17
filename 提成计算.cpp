#include<stdio.h>
int main(){
	long int profit;float award;
	scanf("%ld",&profit);
	if(profit<=100000) award=0.1*profit;
	else if (profit>100000&profit<=200000)
	award=10000+(profit-100000)*0.075;
	else if (profit>200000&profit<=400000)
	award=17500+(profit-200000)*0.05;
	else if (profit>400000&profit<=600000)
	award=27500+(profit-400000)*0.03;
	else if (profit>600000&profit<=1000000)
	award=33500+(profit-600000)*0.015;
	else
	award=39500+(profit-1000000)*0.01;
	printf("%.2f",award);
	return 0;
}
