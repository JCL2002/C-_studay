#include<stdio.h>
int main(){
	int a,list[512],cha;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",&list[i]);
	}//ÊýÖµÂ¼Èë 
	for(int i=1;i<a;i++){
		cha=list[i]-list[i-1];
		if(i%3==0&&i!=0){
			printf("%d\n",cha);
		}
		else{
			printf("%d ",cha);
		}
	}
	return 0;
}
