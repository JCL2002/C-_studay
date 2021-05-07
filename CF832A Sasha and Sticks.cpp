#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n,k,i;
	cin >>n>>k;
	i=n/k;
	if(i&(unsigned long long)1){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}