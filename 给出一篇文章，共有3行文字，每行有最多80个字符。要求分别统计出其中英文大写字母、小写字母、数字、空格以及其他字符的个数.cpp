#include<stdio.h>
int main(){
	char a[3][81];
	for(int i=0;i<3;i++){
		gets(a[i]);
	}
	int Upper=0,Lower=0,number=0,blank=0,other=0;
	for(int i=0;i<3;i++){
		for(int j=0;a[i][j]!='\0';j++){
			//´óÐ´×ÖÄ¸£º65-90
			//Ð¡Ð´×ÖÄ¸£º97- 122
			//¿Õ¸ñ£º32 
			//Êý×Ö£º 48-57
			if(a[i][j]>64&&a[i][j]<91) Upper++;
			else if(a[i][j]>96&&a[i][j]<123) Lower++;
			else if(a[i][j]==32) blank++;
			else if(a[i][j]>47&&a[i][j]<58) number++;
			else other++;
		}
	}
	printf("%d %d %d %d %d\n",Upper,Lower,number,blank,other);
	return 0;
}
