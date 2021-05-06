#include<bits/stdc++.h>
using namespace std;
int main(){
	bool res[100];
	int R=0;
	int t;
	int a[100];
	int n;
	cin >>t;
	for(int j=0;j<t;j++){
		cin >> n;
		for(int k=0;k<n;k++){
			cin >>a[k];
		}
		
		if(n==1){
			res[R]=true;
			R++;
			continue;
		}
		for(int k=0;k<n-1;k++){
			if(abs(a[k]-a[k+1])%2){
				res[R]=false;
				R++;
				break;
			}
			if(k==n-2){
				res[R]=true;
				R++;
			}
		}
	}
	for(int j=0;j<R;j++){
		if(res[j]){
			cout <<"YES";
		}
		else{
			cout <<"NO";
		}
		if(j!=R-1){
			cout <<endl;
		}
	}
	return 0;
}