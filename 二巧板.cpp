#include<bits/stdc++.h>
using namespace std;
double s=0;
int x[7];
int y[7];
int main(){
	cin >>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
//	cin >>x[4]>>y[4]>>x[5]>>y[5]>>x[6]>>y[6];
	s+=abs(0.5*(double)(x[1]*y[2]+x[2]*y[3]+x[3]*y[1]-x[1]*y[3]-x[2]*y[1]-x[3]*y[2]));
	cin >>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
	s+=abs(0.5*(double)(x[1]*y[2]+x[2]*y[3]+x[3]*y[1]-x[1]*y[3]-x[2]*y[1]-x[3]*y[2]));
//	s=abs(s);
	printf("%.2f",s);
	return 0;
}