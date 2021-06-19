#include<bits/stdc++.h>
using namespace std;
int a[4020];
int b[4020];
int tmp[4020];
char in[4010];
void turn (int* target){
	int len=(int)strlen(in);
	for(int i=0;i<len;i++){
		target[len-1-i]=in[i]-'0';
	}
}
void calculate(){//计算结果储存到b
	for(int j=0;j<2009;j++){
		for(int k=0;k<2009;k++){
			tmp[j+k]+=a[j]*b[k];
		}
	}
	int carry=0;int sum;
	for(int i=0;i<4020;i++){//结果累加
		sum=carry+tmp[i];
		carry=sum/10;
		b[i]=sum%10;
	}
}
void display(){
	bool flag=false;
	for(int i=4019;i>-1;i--){
		if(b[i]||!i){
			flag=true;
		}
		if(flag){
			printf("%d",b[i]);
		}
	}
}
int main(){
	cin >>in;
	turn(a);
	cin >>in;
	turn(b);
	calculate();
	display();
	return 0;
}