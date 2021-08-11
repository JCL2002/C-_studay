#include<bits/stdc++.h>
using namespace std;
#define int long long
int exgcd(int a,int b,int& x,int& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
signed main(){
	int x,y,m,n,L;
	cin >>x>>y>>m>>n>>L;
	int a,b,k,z,c;
	a=n-m;b=L;c=x-y;
	if(a<0){
		a=-a;
		c=-c;
	}
	int gcd=exgcd(a,b,k,z);
	if(a==0||(x-y)%gcd!=0){
		cout <<"Impossible";
		return 0;
	}
	k*=(c/gcd);
	k=(k%(b/gcd)+b/gcd)%(b/gcd);
	cout <<k;
	return 0;
}