#include<bits/stdc++.h>
using namespace std;
const int inf=100000000;
int main(){
	int t;cin >>t;
	while(t--){
		int W,H,w,h,x1,y1,x2,y2;
		cin >>W>>H;
		cin >>x1>>y1>>x2>>y2;
		cin >>w>>h;
		int a=inf,b=inf,c=inf,d=inf;
		if(x1>=w) a=0;//×ó±ß
		else if(W-x2+x1>=w){
			a=w-x1;
		}
		if(y1>=h) b=0;//ÏÂ±ß
		else if(H-y2+y1>=h){
			b=h-y1;
		}
		if(W-x2>=w) c=0;//ÓÒ±ß
		else if(W-x2+x1>=w){
			c=x2-W+w;
		}
		if(H-y2>=h) d=0;//ÉÏ±ß
		else if(H-y2+y1>=h){
			d=y2-H+h;
		}
		int mmin=min(a,b);
		mmin=min(mmin,c);
		mmin=min(mmin,d);
		if(mmin==inf)cout <<"-1"<<endl;
		else cout <<mmin<<".000000000"<<endl;
	}
	return 0;
}