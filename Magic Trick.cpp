#include<bits/stdc++.h>
using namespace std;
char inp[70];
int ti[30];
int main(){
	cin >>inp;
	for(int i=0;i<(int)strlen(inp);i++){
		ti[inp[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(ti[i]>1){
			cout <<0;
			return 0;
		}
	}
	cout <<1;
	return 1;
}