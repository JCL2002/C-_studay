#include<bits/stdc++.h>
using namespace std;
int arr[50001];
int l,n,m;
bool judge(int x){
	int j=0;int number=0;
	for(int i=1;i<=n+1;i++){
		if(arr[i]-arr[j]<x){
			number++;
		}
		else{
			j=i;
		}
	}
	if(number>m){
		return false;
	}
	else{
		return true;
	}
}
int main(){
	cin >>l>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	arr[n+1]=l;
	int left=1,right=l;
	while(true){
		if(left==right){
			break;
		}
		int mid=(left+right)/2;
		if(judge(mid)){
			if(judge(mid+1)){
				left=mid+1;
			}
			else{
				right=mid;
				break;
			}
		}
		else{
			
			right=mid-1;
		}
	}
	cout <<right;
	return 0;
}