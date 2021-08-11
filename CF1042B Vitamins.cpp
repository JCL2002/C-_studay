#include<bits/stdc++.h>
//暂时不会做#################################################################
using namespace std;
int m[3]={1000000,1000000,1000000};
char s[4];
int main(){
	int n;
	cin >>n;
	for(int i=0;i<n;i++){
		int val;
		cin >>val>>s;
		for(int j=0;j<(int)strlen(s);j++){
			m[(int) s[j]-'A']=min(m[(int) s[j]-'A'],val);
		}
	}
	cout <<m[0]+m[1]+m[2];
	return 0;
}