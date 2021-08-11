#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long ans=0;
	cin >>n;
	for(int i=1,j=0;i<=n;i=j+1){
		j=n/(n/i);
		ans+=(n/i)*(j-i+1);
	}
	cout <<ans;
}