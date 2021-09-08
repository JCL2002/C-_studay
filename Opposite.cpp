#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin >>t;
	while(t--){
		long long a,b,c;
		long long num;
		cin >>a>>b>>c;
		num=2*abs(a-b);
		if(c>num||a>num||b>num)cout <<-1<<endl;
		else cout <<(c-1+num/2)%num+1<<endl;
	}
	return 0;
}