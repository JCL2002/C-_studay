#include<bits/stdc++.h>
using namespace std;
int arr[200006];
int path[200006];
int main(){
	int n;cin >>n;
	arr[1]=0;
	for(int i=2;i<=n;i++){
		scanf("%d",arr+i);
	}
	int k=0;
	while(true){
//		cout <<"n:"<<n<<"arr[n]:"<<arr[n]<<endl;
		path[k++]=n;
		n=arr[n];
		if(n==0)break;
	}
	for(int i=k-1;i>=0;i--){
		printf("%d ",path[i]);
	}
	return 0;
}