#include<bits/stdc++.h>
using namespace std;
char s[10];
int main(){
	cin >>s;
	int act=0,reg=0;
	act+=36000*(int)(s[0]-'0');
	act+=3600*(int)(s[1]-'0');
	act+=600*(int)(s[3]-'0');
	act+=60*(int)(s[4]-'0');
	reg+=600*(int)(s[0]-'0');
	reg+=60*(int)(s[1]-'0');
	reg+=10*(int)(s[3]-'0');
	reg+=(int)(s[4]-'0');
	int ti=act-reg;
	int hour=ti/3600;
	int min=(ti%3600)/60;
	int sec=ti%60;
	printf("%.2d:%.2d:%.2d",hour,min,sec);
	return 0;
}