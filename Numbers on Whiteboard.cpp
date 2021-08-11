#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin >>t;
	while(t--){
		int n;cin >>n;
		cout <<2<<endl;
		cout <<n<<' '<<n-1<<endl;
		for(int i=n;i>2;i--){
			printf("%d %d\n",i,i-2);
		}
	}
	return 0;
}