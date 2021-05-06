#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,m,k,p,z,MAX;bool poss;
	cin >>n>>m>>k>>p;
	//可能性检测
	//特判k==0
	if(k==0){
		if(p!=n){
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for(int i=0;i<n;i++){
			printf("0 %lld\n",m);
		}
		return 0;
	}
	if(k<p){
		poss=false;
	}
	else if(p==k){
		poss=true;
		z=0;
		MAX=1;
	}
	else{
		int max=k/p;
		if(max>m){
			MAX=m;
			z=k-m*p;
			if(z>(n-p)*(m-1)){
				poss=false;
			}
			else{
				poss=true;
			}
		}
		else{
			MAX=max;
			z=k-max*p;
			if(z>(n-p)*(max-1)){
				poss=false;
			}
			else{
				poss=true;
			}
		}
	}
	if(poss){
		printf("YES\n");
		for(int i=0;i<p;i++){
			printf("%lld %lld\n",MAX,m-MAX);
		}
		if(n==p){
			return 0;
		}
		int basic=z/(n-p);
		int remain=z-basic*(n-p);
		for(int i=0;i<remain;i++){
			printf("%lld %lld\n",basic+1,m-basic-1);
		}
		for(int i=0;i<n-p-remain;i++){
			printf("%lld %lld\n",basic,m-basic);
		}
	}
	else{
		cout <<"NO";
	}
	return 0;
}