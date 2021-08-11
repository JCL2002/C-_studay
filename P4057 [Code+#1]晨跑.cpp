#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b){
	return !b? a:gcd(b,a%b);
}
signed main(){
	int a,b,c,ab;
	cin >>a>>b>>c;
	ab=gcd(a,b);
	ab=a*b/ab;
	cout <<ab*c/gcd(ab,c);
	return 0;
}