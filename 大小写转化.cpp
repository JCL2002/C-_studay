#include<stdio.h>
int main(){
	char c;
	scanf("%c",&c);/*��д��ĸ��65-90*/
	if(c>=65&c<=90) c+=32;
	printf("%c",c);
	return 0;
}
