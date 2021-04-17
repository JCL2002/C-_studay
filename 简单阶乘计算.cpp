#include<stdio.h>
int Factorial( const int N ){
	int k=1;
	if(N<=0){
		return 0;
	}
	else{
		for(int i=1;i<=N;i++){
			k*=i;
		}
		return k;
	}
}
int main()
{
    int N, NF;

    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}
