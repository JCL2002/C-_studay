#include<stdio.h>
int isPalindromicString(char s[]){
	int len,mark=1;
	for(len=0;s[len]!='\0';len++);//ͳ�ƴ����ַ����ĳ���
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]){
			mark=0;
		}
	}
	return mark;
}
int main(){
	char s[100];
	gets(s);
	if(isPalindromicString(s))
		printf("Yes");
	else
		printf("No");
	return 0;
}
