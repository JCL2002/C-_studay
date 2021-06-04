#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5];
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",arr+1,arr+2,arr+3,arr+4);
		int remain1,remain2,max,second=0;
		if(arr[1]>arr[2]){
			remain1=arr[1];
		}
		else{
			remain1=arr[2];
		}
		if(arr[3]>arr[4]){
			remain2=arr[3];
		}
		else{
			remain2=arr[4];
		}
		max=arr[1];
		for(int i=2;i<=4;i++){
			if(arr[i]>max){
				max=arr[i];
			}
		}
		for(int i=1;i<=4;i++){
			if(arr[i]>second&&arr[i]<max){
				second=arr[i];
			}
		}
		if((max==remain1&&second==remain2)||(remain1==second&&remain2==max)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}