#include<bits/stdc++.h>
using namespace std;
int x;
int main(){
	cin >>x;
	if(x==1){
		cout <<-1<<endl;
		return 0;
	}
	if(x%2){//ÆæÊý
		cout <<x-1<<' '<<2<<endl;
	}
	else{
		cout <<x<<' '<<2<<endl;
	}
	return 0;
}