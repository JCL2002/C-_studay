#include<stdio.h>
int reverse( int number ){
	int a,list[256];int i=0;
	//��ȡa��ÿһλ�������������list�� 
	for (;;i++){
		a=number%10;
		number/=10;
		list[i]=a;
		if(!number) break;

	}
	a=0;//��ʼ��a���ڴ�������ۼӺ� 
	for(int j=0;j<=i;j++){
		int k=1;
		for(int h=0;h<(i-j);h++){//����ÿһλ��Ȩ�� 
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
