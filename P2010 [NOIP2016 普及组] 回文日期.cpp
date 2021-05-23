#include<bits/stdc++.h>
using namespace std;
int emulate(int date){//举出当前日期的下一天
	int year=date/10000;
	int month=(date%10000)/100;
	int day=date%100;
	bool rain=false;
	if(year%400==0||(year%4==0&&year%100)){//闰年判断
		rain=true;
	}
	day++;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){//31天的月份
		if(day>31){
			day=1;
			month++;
		}
	}
	else if(month==2){
		if(rain){
			if(day>29){
				day=1;
				month++;
			}
		}
		else{
			if(day>28){
				day=1;month++;
			}
		}
	}
	else{
		if(day>30){
			day=1;
			month++;
		}
	}
	if(month>12){
		month=1;
		year++;
	}
	return year*10000+month*100+day;
}
bool plain(int n){
	int arr[8];
	for(int i=0;i<8;i++){
		arr[i]=n%10;
		n/=10;
	}
	for(int i=0;i<4;i++){
		if(arr[i]!=arr[7-i]) return false;
	}
	return true;
}
int main(){
	int start,end,num=0;
	cin >>start>>end;
	for(int i=start;i<=end;){
		if(plain(i))num++;
		i=emulate(i);
		
	}
	cout <<num;
	return 0;
}