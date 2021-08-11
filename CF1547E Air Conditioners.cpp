#include<bits/stdc++.h>
using namespace std;
const int N=300005;
const long long high=100000000000;
long long temp[N];
int ac[N];
int n,k;
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n>>k;
		for(int i=0;i<=n+1;i++){
			temp[i]=high;
		}
		for(int i=1;i<=k;i++){
			cin >>ac[i];
		}
		for(int i=1;i<=k;i++){
			long long tmp;
			cin >>tmp;
			temp[ac[i]]=tmp;
		}
		for(int i=1;i<=n;i++){
			temp[i]=min(temp[i],temp[i-1]+1);
		}
		for(int i=n;i>0;i--){
			temp[i]=min(temp[i],temp[i+1]+1);
		}
		for(int i=1;i<=n;i++){
			cout <<temp[i]<<" ";
		}
		cout <<endl;
	}
	return 0;
}