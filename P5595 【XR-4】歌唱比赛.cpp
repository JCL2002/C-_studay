#include<bits/stdc++.h>
using namespace std;
char s[1000002];
bool x[1000002];
bool y[1000002];
int main(){
	cin >>s;
	int n=strlen(s);
	for(int i=n-1;i>=0;i--){
		if(s[i]=='Z'){
			if(i<n-1){
				if(s[i+1]!='Z'){
					cout <<"-1";
					return 0;
				}
				else{
					x[i]=false;	
					y[i]=false;
				}	
			}
			else{
				x[i]=false;
				y[i]=false;
			}
		}
		else if(s[i]=='X'){
			x[i]=true;
			y[i]=false;
		}
		else{
			x[i]=false;
			y[i]=true;
		}
	}
	for(int i=0;i<n;i++){
		if(x[i]) printf("1");
		else printf("0");
	}
	printf("\n");
	for(int i=0;i<n;i++){
		if(y[i]) printf("1");
		else printf("0");
	}
	return 0;
}