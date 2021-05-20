#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
	int n;cin >>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int number=0;int max_of_swap=0;
	for(int i=0;i<n;i++){
		if(i==arr[i]){
			number++;
		}
		else if(max_of_swap!=2){
			if(arr[arr[i]]!=arr[i]){//为可交换元素
				if(arr[arr[i]]==i){
					max_of_swap=2;
				}
				else{
					max_of_swap=1;
				}
			}
		}
	}
	//继续判断交换所能诞生的最大的fix点数量
	cout<<number+max_of_swap;
	return 0;
}