#include<bits/stdc++.h>
using namespace std;
char s[20];
int arr[20];
int main(){
	cin >>s;
	for(int i=0;i<(int)strlen(s);i++){
		arr[i]=(int)(s[i]-'A');
	}
	for(int i=2;i<(int)strlen(s);i++){
		if(arr[i]!=(arr[i-1]+arr[i-2])%26){
			cout <<"NO";
			return 0;
		}
	}
	cout <<"YES";
	return 0;
}