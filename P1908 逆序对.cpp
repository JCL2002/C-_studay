#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001];
int cache[500001];
int number=0;
//归并排序-升序排序
void conquer(int left,int mid,int right){
	int f=left;int s=mid;int c=left;
	while(f<mid||s<right){
		if(f<mid&&s<right){
			if(a[f]>a[s]){
				cache[c++]=a[s++];
				number+=(mid-f);//当前元素一定小于第一个子区间的所有元素
			}
			else{
				cache[c++]=a[f++];
			}
		}
		else if(f<mid){
			cache[c++]=a[f++];
		}
		else{
			cache[c++]=a[s++];
		}
	}
	for(int i=left;i<right;i++){
		a[i]=cache[i];
	}
}
void sort(int start,int end){
	if(end-start==1){
		return ;
	}
	int mid=(start+end)/2;
	sort(start,mid);sort(mid,end);
	conquer(start,mid,end);
}
signed main(){
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(1,n+1);
	cout <<number;
	return 0;
}