#include<bits/stdc++.h>
using namespace std;
int main(){
	char name[64];
	unsigned int sum=0,n;
	cin >>n;
	for(unsigned int i=0;i<n;i++){
		scanf("%s",name);
		switch (name[0]){
			case 'T':{
				sum+=4;
				break;
			}
			case 'C':{
				sum+=6;
				break;
			}
			case 'O':{
				sum+=8;
				break;
			}
			case 'D':{
				sum+=12;
				break;
			}
			case 'I':{
				sum+=20;
				break;
			}
		}
	}
	cout <<sum;
	return 0;
}