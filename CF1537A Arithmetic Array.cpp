#include<bits/stdc++.h>
using namespace std;
int sum;
int n;
int main(){
	int t;cin >>t;
	while(t--){
		sum=0;
		cin >>n;
		for(int i=1;i<=n;i++){
			int tmp;
			cin >>tmp;
			sum+=tmp;
		}
		if(sum>=n)cout<<sum-n<<endl;
		else cout <<1<<endl; 
	}
	return 0;
}