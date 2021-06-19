#include<bits/stdc++.h>
using namespace std;
int a[504];
int b[504];
char ca[505];
char cb[505];
void turn(char* in,int* ou){
	int len=(int)strlen(in);
	for(int i=len-1;i>-1;i--){
		ou[len-1-i]=(int)in[i]-'0';
	}
}
void calculate(){//计算结果储存在cb里面
	int carry=0;//进位
	int sum;
	for(int i=0;i<504;i++){
		sum=carry+a[i]+b[i];
		carry=sum/10;
		b[i]=sum%10;
	}
}
void display(){//显示结果
	bool s=false;
	for(int i=503;i>-1;i--){
		if(b[i]>0){
			s=true;
		}
		if(s||!i){
			printf("%d",b[i]);
		}
	}
}
int main(){
	cin >>ca;
	cin >>cb;
	turn(ca,a);
	turn(cb,b);
	calculate();
	display();
	return 0;
}