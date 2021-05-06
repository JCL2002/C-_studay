#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;unsigned int n;
	cin >>t;
	int a[13];int number;
	for(int i=0;i<t;i++){
		cin >>n;
		number=0;
		while(n){
			number++;
			a[number]=n%10;
			n/=10;
		}
		bool flag=true;
		for(int j=number-1;j>0;j--){
			if(a[j]>a[number]){
				break;
			}
			else if(a[j]<a[number]) {
				flag=false;
				break;
			}
		}
		if(flag){
			cout <<a[number]+9*(number-1)<<endl;
		}
		else{
			cout <<a[number]-1+9*(number-1)<<endl;
		}
	}
	return 0;
}