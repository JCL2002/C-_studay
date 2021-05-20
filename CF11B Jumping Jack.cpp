#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x,i;
	cin >>x;
	x=abs(x);
	i=(sqrt(1+8*x)-1)/2;
	if(i*(i+1)<2*x){
		i++;
	}
	if(2*x<i*(i+1)){
		//先判断能不能用最小步+负数完成
		if((i*(i+1)/2-x)%2){
			//不能用最小步完成
			i++;
			if((i*(i+1)/2-x)%2){
				//还不能完成
				i++;
			}
		}
	}
	cout <<i;
	return 0;
}