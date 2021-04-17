#include<stdio.h>
int main(){
	char a[2048];int count=0,tst=1;
	gets(a);
	for(int i=0;a[i]!='\0';i++){
		if(a[i]==' '){
			tst=1;
		}
		else {
			if(tst==1){
				count++;
				tst=0;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
