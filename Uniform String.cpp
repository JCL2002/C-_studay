#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main(){
	cin >>t;
	while(t--){
		cin >>n >>k;
		for(int i=0;i<n;i++){
			printf("%c",'a'+i%k);
		}
		cout <<endl;
	}
	return 0;
}