#include<bits/stdc++.h>
using namespace std;
int num;
int arr[1003];
long long n;
void init(int num){
	for(int i=0;i<=num;i++){
		arr[i]=0;
	}
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		long long cpy=n;
		num=0;
		for(int i=2;(long long)i*i<=n;i++){//拆成最小质因数
			if(n%(long long)i==0){
				arr[++num]=i;
				n/=(long long)i;
				i=1;
			}
		}
		if(n)arr[++num]=n;
//		for(int i=1;i<=num;i++)cout <<arr[i]<<" ";
//		cout <<endl;
		int mmax=0,mmax_i=0;
		int before_i=0,before=arr[0];
		for(int i=1;i<=num;i++){
			if(arr[i]!=before){
				before=arr[i];
				before_i=i;
			}
			else{
				if(i-before_i+1>mmax){
					mmax=i-before_i+1;
					mmax_i=i;
				}
			}
		}
		if(mmax>1){
			cout <<mmax<<endl;
			for(int i=1;i<mmax;i++){
				cout <<arr[mmax_i]<<" ";
				cpy/=arr[mmax_i];
			}
			cout <<cpy<<endl;
		}
		else cout <<1<<endl<<cpy<<endl;
		
	}
	return 0;
}