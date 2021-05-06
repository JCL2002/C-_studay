#include<bits/stdc++.h>
using namespace std;
struct l{
	bool type;//false µÈ²î
	unsigned int a;
	int first;
};
unsigned long long times(int n,int t){
	unsigned long long sum=n;
	for(int i=0;i<t-1;i++){
		sum*=n;
	}
	return sum;
}
int main(){
	l SL[100];
	int a,b,c,d[100];
	int t;
	cin >>t;
	for(int i=0;i<t;i++){
		cin >>a >> b >> c>>d[i];
		if(b*b==a*c){
			SL[i].type=true;
			SL[i].a=b/a;
			SL[i].first=a;
		}
		else{
			SL[i].type=false;
			SL[i].a=b-a;
			SL[i].first=a;
		}
	}
	unsigned long long k;
	for(int i=0;i<t;i++){
		if(SL[i].type){
			k=SL[i].first*times(SL[i].a,(d[i]-1));
		}
		else{
			k=SL[i].first+SL[i].a*(d[i]-1);
		}
		cout <<k%200907;
		if(i!=t-1){
		cout <<endl;
		}
	}
	return 0;
}