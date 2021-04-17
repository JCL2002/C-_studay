#include<stdio.h>
int main(){
	int a;
	while (scanf("%d",&a)!=EOF){
		long long sum=1;
		for (int i=1;i<=a;i++){
			sum*=i;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
