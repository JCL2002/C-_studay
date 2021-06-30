#include<bits/stdc++.h>
using namespace std;
//const int maxn=1e6+5;
//bool vis[maxn];
//int prime[maxn],mu[maxn];
//void init_mu(int n){//init_mu(n) 就可得到1-n的莫比乌斯函数的值，存在mu中
//    int cnt=0;
//    mu[1]=1;
//    for(int i=2;i<n;i++){
//        if(!vis[i]){
//            prime[cnt++]=i;
//            mu[i]=-1;
//        }
//        for(int j=0;j<cnt&&i*prime[j]<n;j++){
//            vis[i*prime[j]]=1;
//            if(i%prime[j]==0)   {mu[i*prime[j]]=0;break;}
//            else { mu[i*prime[j]]=-mu[i];}
//        }
//    }
//}

int main(){
	int t,n;
	cin >>t;
//	init_mu(maxn);
	
	while(t--){
		scanf("%d",&n);
		long long sum=0;
		sum=(long long)n*(long long)(n+1)/2;
		cout <<sum%1000000007<<endl;
	}
	return 0;
}