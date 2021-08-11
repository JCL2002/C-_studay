#include<iostream>
using namespace std;
char arr[200105];

int main(){
	int t;
	cin >>t;
	while(t--){
		int n,m;
		cin >>n>>m;
		for(int i=1;i<=n*2-1;i++){
			for(int j=1;j<=m;j++){
				cin >>arr[i*m+j];
			}
		}
		char output=0;
		for(int i=1;i<=m;i++){
			output=0;
			for(int j=1;j<=n*2-1;j++){
				output^=arr[j*m+i];
			}
			cout <<output;
		}
		cout <<endl;
	}
	
	return 0;
}