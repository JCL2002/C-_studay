#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[302];//储存石子高度
int n;
signed main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	sort(arr+1,arr+1+n);
	int i=1;int sum=0;int before=0;
	while(i<=n){
		if(i&1){
			sum+=abs(arr[n-i/2]-before)*abs(arr[n-i/2]-before);
			before=arr[n-i/2];
		}
		else{
			sum+=abs(arr[i/2]-before)*abs(arr[i/2]-before);
			before=arr[i/2];
		}
		i++;
	}
	cout <<sum;
}