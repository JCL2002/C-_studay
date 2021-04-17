#include<stdio.h>
int main(){
	char inp[81],Find;int j=0;
	scanf("%s\n%s",&Find,&inp);
	for(int i=0;inp[i]!='\0';i++){
		if(inp[i]==Find){
			j=i;
		}
	}
	if(0==j){
		printf("Not Found");
	}
	else{
		printf("index = %d",j);
	}
	return 0;
}
