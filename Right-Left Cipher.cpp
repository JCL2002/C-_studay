#include<bits/stdc++.h>
using namespace std;
char str[53];
char result[53];
int main(){
	cin >>str;
	int len=strlen(str);
	int f=0,last=len-1;
	for(int i=0;i<len;i++){
		if(len%2){//ÆæÊý
			if(i%2){
				result[i]=str[last--];
			}
			else{
				result[i]=str[f++];
			}
		}
		else{
			if(i%2){
				result[i]=str[f++];
			}
			else{
				result[i]=str[last--];
			}
		}
	}
	result[len]='\0';
	for(int i=len-1;i>=0;i--){
		printf("%c",result[i]);
	}
	cout <<endl;
	return 0;
}