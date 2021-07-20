#include<bits/stdc++.h>
using namespace std;
int t;long long n;
int arr[11];
int main(){
	cin >>t;
	while(t--){
		cin >>n;
		for(int i=0;i<11;i++){
			arr[i]=n%10;
			n/=10;
		}
		int MAX=arr[0];
		for(int i=1;i<11;i++){
			MAX=max(arr[i],MAX);
		}
		
		cout <<MAX<<endl;
		
	}
	return 0;
}