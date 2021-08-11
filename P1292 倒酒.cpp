#include<iostream>
using namespace std;
#define ll long long
ll exgcd(ll a,ll b,ll& x,ll& y){
	if(b==0){
		x=1ll;
		y=0ll;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int main(){
	ll a,b,x=0,y=0;
	cin >>a>>b;
	ll g=exgcd(a,b,x,y);
	x=(x%(b/g)-b/g)%(b/g);
	cout <<g<<endl<<-x<<' '<<(g+a*-x)/b;
	return 0;
}