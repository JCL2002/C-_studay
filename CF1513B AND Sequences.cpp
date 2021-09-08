#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long A(int n,int m){
	long long res=1;
	for(int i=0;i<m;i++){
		res=(res*n)%mod;
		n--;
	}
	return res;
}
int arr[200005];
int main(){
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		int And=-1;
		for(int i=1;i<=n;i++){
			cin >>arr[i];
			And &=arr[i];
		}
		for(int i=1;i<=n;i++) arr[i]^=And;
		int num=0;
		for(int i=1;i<=n;i++) if(arr[i]==0) num++;
		if(num<2) cout <<0<<endl;
		else cout <<(long long) A(num,2)*(long long)A(n-2,n-2)%mod<<endl;
//		cout <<(long long) A(n,num)*(long long)A(n-num,n-num)%mod<<endl;
	}
	
	return 0;
}