#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin >>t;
	while(t--){
		int num=0;
		int a,b,c;
		cin >>a>>b>>c;
		if(c){
			c--;
			num++;
		}
		if(b){
			b--;
			num++;
		}
		if(a){
			a--;
			num++;
		}
		int arr[3];
		arr[0]=a;arr[1]=b;arr[2]=c;
		sort(arr,arr+3);
		a=arr[0];b=arr[1];c=arr[2];
		if(b&&c){
			b--;c--;
			num++;
		}
		if(a&&c){
			a--;c--;
			num++;
		}
		if(a&&b){
			a--;b--;
			num++;
		}
		if(a&&b&&c){
			num++;
		}
		cout <<num<<endl;
	}
	
	return 0;
}