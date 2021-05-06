#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >>n;
	char sit[1001][6];bool ok=false;
	for(int i=0;i<n;i++){
		cin >>sit[i];
		if(sit[i][0]=='O'&&sit[i][1]=='O'){
			if(!ok){
				sit[i][0]='+';sit[i][1]='+';
			}
			ok=true;
		}
		if(sit[i][3]=='O'&&sit[i][4]=='O'){
			if(!ok){
				sit[i][3]='+';sit[i][4]='+';
			}
			ok=true;
		}
	}
	if(ok){
		cout <<"YES"<<endl;
	}
	else{
		cout <<"NO";
		return 0;
	}
	for(int i=0;i<n;i++){
		cout <<sit[i]<<endl;
	}
	return 0;
}