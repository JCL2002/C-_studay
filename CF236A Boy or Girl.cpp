#include<bits/stdc++.h>
using namespace std;
char str[120];
int num[256];
int main(){
	cin >>str;
	for(int i=0;i<(int)strlen(str);i++){
		num[(int)str[i]]++;
	}
	int sum=0;
	for(int i=(int)'a';i<=(int)'z';i++){
		if(num[i]) sum++;
	}
	if(sum%2){
		cout <<"IGNORE HIM!";
		return 0;
	}
	cout <<"CHAT WITH HER!";
	return 0;
}