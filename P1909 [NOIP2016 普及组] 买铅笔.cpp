#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int kind[3][2];
	cin >>n;
	cin >> kind[0][0] >> kind[0][1];
	cin >> kind[1][0] >> kind[1][1];
	cin >> kind[2][0] >> kind[2][1];
	int val[3],number;
	
	number=n/kind[0][0];
	if(n%kind[0][0]){
		number++;
	}
	val[0]=number*kind[0][1];
	
	
	number=n/kind[1][0];
	if(n%kind[1][0]){
		number++;
	}
	val[1]=number*kind[1][1];
	
	
	number=n/kind[2][0];
	if(n%kind[2][0]){
		number++;
	}
	val[2]=number*kind[2][1];
	int min=val[0];
	if(val[1]<min){
		min=val[1];
	}
	if(val[2]<min){
		min=val[2];
	}
	cout <<min;
	return 0;
}