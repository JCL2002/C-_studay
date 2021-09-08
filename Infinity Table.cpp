#include<bits/stdc++.h>
using namespace std;
long long k;
int main(){
	int t;cin >>t;
	while(t--){
		cin >>k;
		long long s=sqrt(k);
		if(s*s<k) s++;
		long long begin=(s-1)*(s-1)+1;
		long long x,y;
		if(k-begin<s){
			y=s;
			x=k-begin+1;
		}
		else{
			x=s;
			y=s*s-k+1;
		}
		cout <<x<<" "<<y<<endl;
	}
	return 0;
}