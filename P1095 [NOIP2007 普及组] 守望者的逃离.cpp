#include<bits/stdc++.h>
using namespace std;
int s,t,m;
int main(){
	cin >>m>>s>>t;
	int run=0,megic=0;
	for(int i=1;i<=t;i++){
		run+=17;
		if(m>=10){
			megic+=60;
			m-=10;
		}
		else{
			m+=4;
		}
		if(megic>run) run=megic;
		if(run>=s){
			cout <<"Yes"<<endl;
			cout <<i;
			return 0;
		}
		if(i==t){
			cout <<"No"<<endl;
			cout <<run;
		}
	}
	
	return 0;
}