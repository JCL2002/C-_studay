#include<bits/stdc++.h>
using namespace std;
int ti[100005];
int n,k;
int arr[100005];

void init(int n){
	for(int i=1;i<=n;i++){
		ti[i]=0;
	}
}

struct M{
	int i;
	int color;
	bool used;
};


M line[100005];

bool cmp(M a,M b){
	return a.i<b.i;
}

int bsearch(int x){//二分查找
	int l=1,mid,r=n;
	mid=(l+r)/2;
	while(l<r){
		if(r-l==1){
			if(line[l].i==x&&line[l].used==false){
				line[l].used=true;
				return line[l].color;
			}
			else if(line[r].i==x&&line[r].used==false){
				line[r].used=true;
				return line[r].color;
			}
			else {
				return 0;
			}
		}
		mid=(l+r)/2;
		if(line[mid].i==x&&line[mid].used==false){
			r=mid;
		}
		else if(line[mid].i==x&&line[mid].used){
			l=mid+1;
		}
		else if(line[mid].i>x){
			r=mid-1;
		}
		else if(line[mid].i<x){
			l=mid+1;
		}
	}
	return 0;
}

int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n>>k;
		for(int i=1;i<=n;i++){//数量统计
			scanf("%d",arr+i);
			if(ti[arr[i]]<k) ti[arr[i]]++;
		}
		int sum=0;
		for(int i=1;i<=n;i++){//转存结构体
			if(ti[i]){
				for(int j=1;j<=ti[i];j++){
					line[sum].i=i;
					line[sum].color=sum%k+1;
					line[sum].used=false;
					sum++;
				}
			}
		}
		sort(line,line+sum,cmp);
		for(int i=1;i<=n;i++){
			cout <<bsearch(arr[i])<<' ';
		}
		cout <<endl;
		init(n);
	}
	return 0;
}