#include<iostream>
using namespace std;
int a[150];
int main(){
	int t;
	for(cin>>t;t;t--){
		int n;cin >>n;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin >>a[i];
			if(a[i]<0) flag=false;
		}
		if(flag){
			cout <<"YES"<<endl<<101<<endl;
			for(int i=0;i<=100;i++){
				cout <<i<<' ';
			}
			cout <<endl;
		}
		else{
			cout <<"NO"<<endl;
		}
	}
	return 0;
}