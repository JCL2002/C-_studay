#include<stdio.h>
#include<string.h>
int main(){
	char a[3][101],max[101];
	for(int i=0;i<3;i++){
		scanf("%s",&a[i]);
	}
	strcpy(max,a[0]);
	for(int i=1;i<3;i++){
		if(strcmp(a[i],max)>0){
			strcpy(max,a[i]);
		}
	}
	printf("%s\n",max);
}
