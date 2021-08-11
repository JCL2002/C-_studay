#include<bits/stdc++.h>
using namespace std;

int n;long long m;
int arr[1000002];

bool test(int mid){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(arr[i]>mid) sum+=arr[i]-mid;
	}
	if(sum>=m) return true;
	return false;
}

int main(){
	cin >>n>>m;
	int MIN=1000001,MAX=0;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
		MIN=min(MIN,arr[i]);
		MAX=max(MAX,arr[i]);
	}
	int mid=(MIN+MAX)/2;
	while(MIN<MAX){
		if(MAX-MIN==1){
			if(test(MIN)){
				mid=MIN;
				break;
			}
			else{
				mid=MAX;
				break;
			}
		}
		else{
			mid=(MAX+MIN)/2;
			if(test(mid)){
				MIN=mid;
			}
			else{
				MAX=mid;
			}
		}
	}
	cout <<mid;
	return 0;
}