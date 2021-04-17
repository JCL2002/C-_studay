#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int nulst[a];
	for(int i=0;i<a;i++){
		scanf("%d",&nulst[i]);
	}
	int max=nulst[0],min=nulst[0];
	for(int i=0;i<a;i++) if(nulst[i]>max) max=nulst[i];
	for(int i=0;i<a;i++) if(nulst[i]<min) min=nulst[i];
	printf("Max=%d Min=%d",max,min);
	return 0;
}
