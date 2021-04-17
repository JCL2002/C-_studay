#include<stdio.h>
int search( int n){
	int count=0;
	for(int i=101;i<=n;i++){
		for(int j=11;j<32;j++){
			if(j*j==i){
				if((i/100==i%10)||(i/100==(i%100)/10)||(i%10==(i%100)/10)){
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{
    int number;

    scanf("%d",&number);
    printf("count=%d\n",search(number));

    return 0;
}
