#include<bits/stdc++.h>
using namespace std;
int ti[257];
char str[60];
void init(){
	for(int i=0;i<256;i++){
		ti[i]=0;
	}
}
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>str;
		init();
		for(int i=0;i<(int)strlen(str);i++){
			if(ti[(int)str[i]]<2) ti[(int)str[i]]++;
		}
		int sum=0;
		for(int i=(int)'a';i<=(int)'z';i++){\
			sum+=ti[i];
		}
		cout <<sum/2<<endl;
	}
	return 0;
}