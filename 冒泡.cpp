#include<stdio.h>
int main(){
	int a[10];int i;
	for (i=0;i<10;i++) scanf("%d",&a[i]);
	int k,j,t;
	/*ц╟ещ*/
	for (j=9;j>=0;j--){
		for(k=0;k<j;k++){
			if (a[k]>a[k+1]){
				t=a[k];a[k]=a[k+1];a[k+1]=t;
			}
		}
	}
	for (i=0;i<10;i++) printf("%d ",a[i]);
	return 0;
}
