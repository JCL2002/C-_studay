#include<bits/stdc++.h>
using namespace std;
int y,b,r;
int main(){
	cin >>y>>b>>r;
	int m=900000000;
	m=min(m,y);
	m=min(m,b-1);
	m=min(m,r-2);
	cout <<3*m+3<<endl;
	return 0;
}