#include<bits/stdc++.h>
using namespace std;
#define  ll long long
ll mem[21][21][21];
ll power(ll x,ll a){
	ll sum=1;
	while(a){
		if(a&1){
			sum*=x;
		}
		x*=x;
		a>>=1;
	}
	return sum;
}
ll w(ll a,ll b,ll c){
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	if(a>20||b>20||c>20){
		return w(20,20,20);//这个数先得计算出来
	}
	if(a==b&&b==c){//当三者相等时，为2^a,历用发现的规律优化
		return power(2,a);
	}
	if(a<b&&b<c){
		if(mem[a][b][c]){
			return mem[a][b][c];
		}
		mem[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		return mem[a][b][c];
	}
	if(mem[a][b][c]){
		return mem[a][b][c];
	}
	mem[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return mem[a][b][c];
}
int main(){
	ll a,b,c;
	while(true){
		cin >>a >>b>>c;
		if(a==-1&&b==-1&&c==-1){
			return 0;
		}
		cout <<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
	}
	return 0;
}