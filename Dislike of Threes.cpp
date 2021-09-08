#include<bits/stdc++.h>
using namespace std;
int arr[2003];
int main(){
	int t;cin >>t;
	int num=0;
	for(int i=1;i<2000;i++){
		if(i%3&&i%10!=3)arr[++num]=i;
	}
	while(t--){
		int k;
		cin >>k;
		cout <<arr[k]<<endl;
		
	}
	return 0;
}