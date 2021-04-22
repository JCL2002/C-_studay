#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned int a;
	int j;
	for(a=0;a<64;a++){
		for(j=5;j>=0;j--){
			if(a&(1<<j)){
				cout <<'1';
			}
			else{
				cout <<'0';
			}
		}
		cout <<endl;
	}
	return 0;
}