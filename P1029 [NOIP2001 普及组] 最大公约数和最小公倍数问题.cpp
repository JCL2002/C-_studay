#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){
	if(a==0) {
		return b;
	}
	else{
		return gcd(b%a,a);
	}
}
signed main(){
	int x,y;
	cin >>x>>y;
	int ans=0;bool mark=false;
	for(int i=1;i<=sqrt(x*y);i++){
		if(x*y%i==0){
			//能够整除才有判断的必要
			if(x==gcd(i,x*y/i)){
				ans++;
				if(i*i==x*y){
					mark=true;
				}
			}
		}
	}
	if (mark){
		cout <<ans*2-1;
	}
	else{
		cout <<ans*2;
	}
	
	return 0;
}