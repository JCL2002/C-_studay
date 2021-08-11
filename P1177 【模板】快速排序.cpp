#include<bits/stdc++.h>
using namespace std;
int n;

int arr[1145140];
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		printf("%d",arr[i]);
		if(i!=n) printf(" ");
	}
	cout <<endl;
	return 0;
}