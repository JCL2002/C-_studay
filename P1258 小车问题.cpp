#include<bits/stdc++.h>
using namespace std;
int main(){
	double s,a,b;
	cin >>s>>a>>b;
	double x=s*(b+a)/(3*a+b);
	printf("%.6f",(x/b+(s-x)/a));
	return 0;
}