#include<bits/stdc++.h>
using namespace std;
char str[1050];
int num[256];
int k,n;
int main(){
	cin >>k;
	cin >> str;
	n=strlen(str);
	for(int i=0;i<n;i++){
		num[(int)str[i]]++;
	}
	for(int i=(int)'a';i<=(int)'z';i++){
		if(num[i]%k){
			cout <<-1;
			return 0;
		}
		else{
			num[i]/=k;
		}
	}
	for(int i=0;i<k;i++){
		for(int i=(int)'a';i<=(int)'z';i++){
			for(int j=0;j<num[i];j++){
				printf("%c",(char)i);
			}
		}
	}
	return 0;
}