#include<stdio.h>
int main(){
	char input[50];
	gets(input);
	for(int i=0;input[i]!=0;i++){
		if ((65<=input[i]&&input[i]<=87)||(97<=input[i]&&input[i]<=119))
		{
			input[i]+=3;
		}
		else input[i]-=23;
	}
	puts(input);
	return 0;
}
