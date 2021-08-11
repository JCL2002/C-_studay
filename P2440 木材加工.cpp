#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[100002];

bool test(int mid){
	int number=0;
	for(int i=1;i<=n;i++){
		number+=arr[i]/mid;
	}
	if(number>=k)return true;
	return false;
}

int main(){
	cin >>n>>k;
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
		sum+=arr[i];
	}
	int MAX=sum/k;
	if(MAX==0){
		cout <<0;
		return 0;
	}
	int MIN=1;
	int mid=(MIN+MAX)/2;
	while(MIN<MAX){
		if(MAX-MIN==1){
			if(test(MAX)){
				mid=MAX;
				break;
			}
			else{
				mid=MIN;
				break;
			}
		}
		mid=(MIN+MAX)/2;
		if(test(mid)){
			MIN=mid;
		}
		else{
			MAX=mid;
		}
	}
	cout <<mid;
	return 0;
}