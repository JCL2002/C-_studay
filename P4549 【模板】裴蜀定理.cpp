#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n,ans;
	cin >>n;
	int a;
	scanf("%d",&ans);
	for(int i=1;i<n;i++){
		a=ans;
		scanf("%d",&ans);
		ans=abs(ans);
		ans=gcd(a,ans);
	}
	cout <<ans;
	return 0;
}