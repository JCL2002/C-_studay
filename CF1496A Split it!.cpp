#include<bits/stdc++.h>
using namespace std;
char str[256];
int main(){
	int t,n,k;
	cin >>t;
	while(t--){
		cin >>n>>k;
		cin >>str;
		bool flag=true;
		for(int i=0;i<k;i++){
			if(str[i]!=str[n-i-1]){
				flag=false;
				break;
			}
		}
		if(2*k+1<=n&&(flag||k==0)) cout << "YES"<<endl;
		else cout <<"NO"<<endl;
	}
	return 0;
}