#include<bits/stdc++.h>
using namespace std;
int emulate(int date){//�ٳ���ǰ���ڵ���һ��
	int year=date/10000;
	int month=(date%10000)/10;
	int day=date%100;
	bool rain=false;
	if(year%400==0||(year%4==&&year%100)){//�����ж�
		rain=true;
	}
	day++;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){//31����·�
		if(day>31){
			day=0;
			month++;
		}
	}
}
int main(){
	int start,end;
	cin >>start>>end;
	return 0;
}