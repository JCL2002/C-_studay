#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1000006];
const int mod = 1000000007;
long long power(int x){
	long long sum=1;
	long long base=2;
	while(x){
		if(x&1) sum=(base*sum%mod)%mod;
		base=(base%mod*base%mod)%mod;
		x>>=1;
	}
	return sum;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	long long sum=0;
	for(int begin=1;begin<=n-2;begin++){
		if(arr[begin]==1){
			for(int end=begin+2;end<=n;end++){
				if(arr[end]==3){
					//¼ÆËãÇø¼äbegin-end
					int a=0;
					for(int k=begin;k<=end;k++){
						if(arr[k]==2)a++;
					}
					sum=(sum%mod+(power(a)-1)%mod)%mod;
				}
			}
		}
	}
	cout <<sum;
	return 0;
}