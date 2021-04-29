#include<bits/stdc++.h>
using namespace std;
int List[1000001];
int find(int k,int n){
	int left=0,right=n-1,i;
	i=(left+right)/2;
//	while(left<right){
//		if(k>List[i]){
//			left=i+1;
//		}
//		else{
//			right=i;
//		}
//		i=(left+right)/2;
//	}
//	if(List[i]==k){
//		return i+1;
//	}
//	else{
//		return -1;
//	}
	while(true){
		if(k>List[i]){
			left=i+1;
			i=(left+right)/2;
		}
		else if(k==List[i]){
			if(!i){
				return 1;
			}
			else{
				if(List[i-1]==k){
					right=i-1;
					i=(left+right)/2;
				}
				else{
					return i+1;
				}
			}
		}
		else{
			right=i;
			i=(left+right)/2;
		}
		if(right==left){
			if(List[i]==k){
				break;
			}
			else{
				return -1;
			}
		}
	}
	return i+1;
	
}
int main(){
	int n,m,k;
	cin >>n >>m;
	for(int j=0;j<n;j++){
		scanf("%d",List+j);
	}
	for(int j=0;j<m;j++){
		scanf("%d",&k);
		printf("%d",find(k,n));
		if(j!=m-1){
			printf(" ");
		}
	}
}