#include<bits/stdc++.h>
using namespace std;
long long  sum[100005];//前缀和数组
int N,M;

bool test(long long res){
	long long stand=0ll;int j=1;
	for(int i=1;i<=N;i++){
		if(sum[i]-stand>res){
			if(sum[i]-sum[i-1]<=res){
				j++;
				stand=sum[i-1];
				if(j>M) return false;
			}
			else{//单个的大小比res大
				return false;
			}
		}
	}
	return true;
}

int main(){
	cin >>N>>M;
	long long MIN=900000000000;
	for(int i=1;i<=N;i++){
		int tmp;
		scanf("%d",&tmp);
		sum[i]=sum[i-1]+tmp;
		MIN=min(MIN,(long long)tmp);
	}
	long long MAX=sum[N];
	long long mid=(MIN+MAX)/2;
	while(MIN<MAX){
		if(MAX-MIN==1){
			if(test(MIN)){
				mid=MIN;
				break;
			}
			else{
				mid=MAX;
				break;
			}
		}
		mid=(MIN+MAX)/2;
		if(test(mid)){
			MAX=mid;
		}
		else{
			MIN=mid;
		}
	}
	cout <<mid<<endl;
	return 0;
}