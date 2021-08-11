#include<bits/stdc++.h>
using namespace std;
int NEXT[1000006];
char s[1000006];
int n;
int main(){
	cin >>n;
	cin >>s;
	NEXT[0]=0;
	int j=0;
	for(int i=1;i<n;i++){
		while(j>0&&s[i]!=s[j])j=NEXT[j-1];
		if(s[i]==s[j]) j++;
		NEXT[i]=j;
	}
	cout <<n-NEXT[n-1];
	return 0;
}