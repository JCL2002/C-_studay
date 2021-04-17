#include<stdio.h>
int main(){
	long long N,x,Pian_Yi;
	scanf("%lld",&N);
	for(x=1;(x*(x+1)<2*N);x++);//算出在第x“行” 
	Pian_Yi=(x*(x+1))/2-N;//算出偏移量 
	//奇数行从第一行开始；偶数行从第一列开始；
	if(x%2==0){
		printf("%lld/%lld",x-Pian_Yi,Pian_Yi+1);
	} 
	else{
		printf("%lld/%lld",Pian_Yi+1,x-Pian_Yi);
	}
}
