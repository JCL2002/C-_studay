#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long x,sum=1;
	int n;
	cin >>x>>n;
	for(int i=0;i<n;i++){
		sum=(x+1)*sum;
	}
	cout <<sum;
	return 0;
}