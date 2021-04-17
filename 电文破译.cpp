#include<stdio.h>
#include<string.h>
//大写字母：65-90
//小写字母：97- 122
//空格：32 
//数字： 48-57
int main(){
	char a[101];
	char Uswap(char a);
	char Lswap(char a);
	gets(a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]>64&&a[i]<91) a[i]=Uswap(a[i]);
		else if(a[i]>96&&a[i]<123) a[i]=Lswap(a[i]);
	}
	printf("%s\n",a);
}
char Uswap(char a){
	return 155-a;
}
char Lswap(char a){
	return 219-a;
}
