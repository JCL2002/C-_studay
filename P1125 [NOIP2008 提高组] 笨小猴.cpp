#include<bits/stdc++.h>
using namespace std;
char str[105];
int num[256];
bool prim(int x){
	if(x<2) return 0;
	for(int i=2;i<x/2+1;i++){
		if(!x%i) return 0;
	}
	return 1;
}
int main(){
	cin >>str;
	int n=strlen(str);
	for(int i=0;i<n;i++){
		num[(int)str[i]]++;
	}
	int mi=1000,ma=0;
	for(int i=(int)'a';i<=(int)'z';i++){
		if(num[i]){
			mi=min(mi,num[i]);
			ma=max(ma,num[i]);
		}
	}
	if(prim(ma-mi))cout <<"Lucky Word"<<endl<<ma-mi;
	else cout <<"No Answer"<<endl<<0;
	return 0;
}