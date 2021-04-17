#include<stdio.h>
int reverse( int number ){
	int a,list[256];int i=0;
	//算取a的每一位并倒序存在数组list中 
	for (;;i++){
		a=number%10;
		number/=10;
		list[i]=a;
		if(!number) break;

	}
	a=0;//初始化a用于存放数组累加和 
	for(int j=0;j<=i;j++){
		int k=1;
		for(int h=0;h<(i-j);h++){//计算每一位的权重 
			k*=10;
		}
		a+=k*list[j];
	}
	return a;
}
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}
