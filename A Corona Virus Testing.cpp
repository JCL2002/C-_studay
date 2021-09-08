#include<bits/stdc++.h>
using namespace std;
int main(){
	int g,p,t;
	cin >>g>>p>>t;
	if(g*p>(g+p*t)) cout <<2;
	else if(g*p==g+p*t) cout <<0;
	else cout <<1;
	return 0;
}