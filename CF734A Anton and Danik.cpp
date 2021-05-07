#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;int n;
	cin >>n;cin >>str;
	unsigned int a=0,d=0;
	for(int i=0;i<n;i++){
		if(str[i]=='A') a++;
		else d++;
	}
	if(a>d) printf("Anton");
	else if(a==d) printf("Friendship");
	else printf("Danik");
	return 0;
}