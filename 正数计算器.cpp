#include<stdio.h>
int main(){
	int a,c,result;char b;
	scanf("%d %c %d",&a,&b,&c);
	switch (b){
		case '+': result=a+c; printf("%d + %d = %d",a,c,result);break;
		case '-': result=a-c; printf("%d - %d = %d",a,c,result);break;
		case '*': result=a*c; printf("%d * %d = %d",a,c,result);break;
		case '/': result=a/c; printf("%d / %d = %d",a,c,result);break;
	}
	return 0;
}
