#include<stdio.h>
int main(){
	long long n=1;double count=0;int k;
	scanf("%d",&k);
	for(;;n++){
		count+=1.0/n;
		if(count>k){
			break;
		}
	}
	printf("%lld",n);
	return 0;
}
