#include<bits/stdc++.h>
using namespace std;
char x[1200];
char y[1200];
int main(){
	cin >>x;
	cin >>y;
	int a=0;int b=0;
	for(int i=0;i<(int)strlen(x);i++){
		if(x[i]=='S')a++;
	}
	for(int i=0;i<(int)strlen(y);i++){
		if(y[i]=='S')b++;
	}
	for(int i=0;i<a*b;i++){
		printf("S(");
	}
	printf("0");
	for(int i=0;i<a*b;i++){
		printf(")");
	}
	return 0;
}