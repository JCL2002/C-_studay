#include<bits/stdc++.h>
using namespace std;
char title[100];
int main(){
	gets(title);
	int i=0,number=0;
	while(title[i]!='\0'&&title[i]!='\n'){
		if(title[i]!=' ')number++;
		i++;
	}
	cout <<number;
	return 0;
}