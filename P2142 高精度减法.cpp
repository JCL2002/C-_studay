#include<bits/stdc++.h>
using namespace std;
int a[10089];
int b[10089];
char ca[10089];
char cb[10089];
void turn(char* in,int* ou){
	int len=(int)strlen(in);
	for(int i=0;i<len;i++){
		ou[len-1-i]=in[i]-'0';
	}
}
void calculate_b(){//计算结果存储在数组b-=a里面
	int carry=0;int tmp;
	for(int i=0;i<10089;i++){
		tmp=carry+a[i]-b[i];
		carry=0;
		if(tmp<0){
			carry--;
			tmp+=10;
		}
		b[i]=tmp;
	}
}
void calculate_a(){//计算结果存储在数组a-=b里面
	int carry=0;int tmp;
	for(int i=0;i<10089;i++){
		tmp=carry-a[i]+b[i];
		carry=0;
		if(tmp<0){
			carry--;
			tmp+=10;
		}
		a[i]=tmp;
	}
}
bool cmp(){//a>=b,返回true
	for(int i=10088;i>-1;i--){
		if(a[i]||b[i]){
			if(a[i]>b[i]){
				return true;
			}
			else if(a[i]==b[i]){
				continue;
			}
			return false;
		}
	}
	return true;
}
void display_b(){
	bool flag=false;
	for(int i=10088;i>-1;i--){
		if(b[i]){
			flag=true;
		}
		if(flag||!i){
			printf("%d",b[i]);
		}
	}
}
void display_a(){
	bool flag=false;
	for(int i=10088;i>-1;i--){
		if(a[i]){
			flag=true;
		}
		if(flag||!i){
			printf("%d",a[i]);
		}
	}
}
int main(){
	cin >>ca;
	cin >>cb;
	turn(ca,a);turn(cb,b);
	if(cmp()){
		calculate_b();
		display_b();
	}
	else{
		calculate_a();
		printf("-");
		display_a();
	}
	return 0;
}