#include<stdio.h>
#include<string.h>
int main(){
	int n,len;char ch[256][81],carry[81];
	scanf("%d",&n);
	//×Ö·û´®Â¼Èë 
	for(int i=0;i<n;i++){
		scanf("%s",&ch[i]);
	}
	strcpy(carry,ch[0]);
	for(int i=1;i<n;i++){
		if(strcmp(carry,ch[i])>0){
			strcpy(carry,ch[i]);
		}
	}
	printf("Min is: %s",carry);
}
