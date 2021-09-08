#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >>n;
	int C=0,C_E=0,T=0,T_E=0;
	for(int i=1;i<=n;i++){
		int e,v1,v2;
		cin >>e>>v1>>v2;
		C+=v1;T+=v2;
		if(v1>v2) C_E+=e;
		else T_E+=e;
	}
//	cout <<C<<"  "<<C_E<<"  "<<T<<"   "<<T_E<<endl;
	if(C>T&&C_E>T_E) cout <<1;
	else if(C<T&&C_E<T_E) cout <<2;
	else cout <<0;
	return 0;
}