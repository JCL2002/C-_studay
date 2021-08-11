#include<bits/stdc++.h>
using namespace std;
char word[256];
int main(){
	int n;
	cin >>n;
	while(n--){
		cin >>word;
		if(strlen(word)>10){
			cout << word[0]<<strlen(word)-2<<word[strlen(word)-1]<<endl;
		}
		else cout <<word<<endl;
	}
	return 0;
}