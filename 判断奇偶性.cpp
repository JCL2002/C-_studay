#include<stdio.h>
int even(int n){
	if(n%2){
		return 0;
	}
	else{
		return 1;
	}
}
int main()
{    
    int n;
    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);  //ż��
    else
        printf("%d is odd.\n", n);   //����
    return 0;
}
