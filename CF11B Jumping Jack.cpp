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
		//���ж��ܲ�������С��+�������
		if((i*(i+1)/2-x)%2){
			//��������С�����
			i++;
			if((i*(i+1)/2-x)%2){
				//���������
				i++;
			}
		}
	}
	cout <<i;
	return 0;
}