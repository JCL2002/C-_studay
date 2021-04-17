#include<stdio.h>
int main(){
	char inp[81],out[82],count[11]="0123456789";int j=0;
	scanf("%s",&inp);
	for(int i=0;inp[i]!='\0';i++){
		for(int k=0;k<10;k++){
			if(inp[i]==count[k]){
				out[j]=inp[i];
				j++;
			}
		}
	}
	out[j]='\0';
	printf("%s",out);
	return 0;
}
