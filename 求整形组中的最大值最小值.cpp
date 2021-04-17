#include<stdio.h>
int main(){
	int inp;
	int max(int a[],int len);int min(int a[],int len);
	scanf("%d",&inp);
	int a[100];
	for (int i=0;i<inp;i++){
		scanf("%d",&a[i]);
	}
	int Max=max(a,inp);
	int Min=min(a,inp);
	printf("%max= %d,min= %d",Max,Min);
	
}
int min(int a[],int len){
	int min=a[0];
	for(int i=1;i<len;i++){
		if (min>a[i]) min=a[i];
	}
	return min;
}
int max(int a[],int len){
	int max=a[0];
	for(int i=1;i<len;i++){
		if (max<a[i]) max=a[i];
	}
	return max;
}
