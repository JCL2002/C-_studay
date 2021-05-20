#include<bits/stdc++.h>
using namespace std;
int kinds[2501];
int type[15];
int main(){
	int t,n;
	cin >>t>>n;
	for(int i=0;i<t;i++){
		cin >>type[i];
	}
	kinds[0]=1;
	for(int i=0;i<t;i++){
		for(int j=1;j<=n;j++){
			if(j>=type[i]){//可以用当前币值支付
				kinds[j]+=kinds[j-type[i]];
			}
		}
	}
	cout <<kinds[n]<<endl;
	//for(int i=1;i<=n;i++){
	//	cout<<kinds[i]<<endl;
	//}
	return 0;
}
