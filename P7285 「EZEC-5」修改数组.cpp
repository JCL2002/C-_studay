#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	cin >>t;
	for(int i=0;i<t;i++){
		cin >> n;
		int number=0;char in;
		for(int j=0;j<n;j++){
			cin >>in;
			if(in=='1') number++;
		}
		printf("%d\n",number);
		for(int j=0;j<n;j++){
			printf("1");
			if(j!=n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}