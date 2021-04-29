#include<bits/stdc++.h>
using namespace std;
struct res{
	char tpye;//'i':整型‘%’百分数型，‘/’分数型，‘.’小数型
	unsigned long long INT;
	unsigned long long fenmu;
	unsigned long long FLOAT;//小数部分
}result;
void read(char* input){
	unsigned long long INT=0,fenmu=0,FLOAT=0;
	char type='i';
	for(int j=0;j<(int)strlen(input);j++){
		switch(input[j]){
			case '/':{
				type='/';
				continue;
				break;
			}
			case '%':{
				type='%';
				continue;
				break;
			}
			case '.':{
				type='.';
				continue;
				break;
			}
		}
		switch(type){
			case 'i':{
				INT*=10;
				INT+=(input[j]-'0');
				break;
			}
			case '.':{
				FLOAT*=10;
				FLOAT+=(input[j]-'0');
				break;
			}
			case '/':{
				fenmu*=10;
				fenmu+=(input[j]-'0');
				break;
			}
		}
	}
	result.fenmu=fenmu;
	result.FLOAT=FLOAT;
	result.INT=INT;
	result.tpye=type;
	return ;
}
void reverse(unsigned long long* input){
	int list[20],j=0;
	while(*input){
		list[j]=*input%10;
		*input/=10;
		j++;
	}
	for(int i=0;i<j;i++){
		*input*=10;
		*input+=list[i];
	}
}
int main(){
	char input[50];
	cin >>input;
	read(input);
	switch(result.tpye){
		case 'i':{
			reverse(&result.INT);
			cout << result.INT;
			break;
		}
		case '%':{
			reverse(&result.INT);
			cout << result.INT<<'%';
			break;
		}
		case '/':{
			reverse(&result.INT);
			reverse(&result.fenmu);
			cout <<result.INT <<'/'<<result.fenmu;
			break;
		}
		case '.':{
			reverse(&result.INT);
			reverse(&result.FLOAT);
			cout <<result.INT <<'.'<<result.FLOAT;
			break;
		}
	}
	return 0;
}