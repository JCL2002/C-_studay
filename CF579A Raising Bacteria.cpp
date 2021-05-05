#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned int x;
	cin >>x;
	int n=0;
	for(int i=0;i<32;i++){
		if(x&(1<<i)) n++;
	}
	cout <<n;
	return 0;
}