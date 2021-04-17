#include<iostream>
using namespace std;
#define PI 3.14159265
int main(){
	long long y,i=1,k=1,JC;//i用于循环，y是原题中的y，JC用于求阶乘
	cout << "请输入一个角度:"<<endl;
	cin >> y;
	double x;
	double current,M,sinx=0;
	x=y*PI/180;
	while(1){
		//计算阶乘、幂次方
		if(i!=1){
			k++;
			JC*=k;
			k++;
			JC*=k;
			M*=(x*x);
		}
		else {
			JC=i;
			M=x;
		}
		current=M/JC;
		if(current<0.0000001){
			break;
		}
		else{
			if(i%2){//奇数项
				sinx+=current;
			}
			else{
				sinx-=current;
			}
		}
		i++;
	}
	cout << sinx;
	return 0;
}