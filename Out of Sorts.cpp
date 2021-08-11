#include<bits/stdc++.h>
using namespace std;

long long arr[110];
long long  O[110];//ÅÅºÃÐòµÄ

long long n,m,a,c;

bool search(long long target){
	int left=1;int right=n;int mid;
	while(left<right){
		mid=(left+right)/2;
		if(O[mid]==target) return true;
		else if(O[mid]>target){
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	if(O[left]==target){
		return true;
	}
	return false;
}

int main(){
	cin >>n>>m>>a>>c>>arr[0];
	for(int i=1;i<=n;i++){
		arr[i]=(a*arr[i-1]+c)%m;
		O[i]=arr[i];
	}
	sort(arr+1,arr+1+n);
	int number=0;
//	for(int i=1;i<=n;i++){
//		cout <<arr[i]<<" ";
//	}
//	cout <<endl;
//	for(int i=1;i<=n;i++){
//		cout <<O[i]<<' ';
//	}
//	cout <<endl;
	for(int i=1;i<=n;i++){
		if(search(arr[i])){
			number++;
//			cout <<"find:"<<arr[i]<<endl;
		}
	}
	cout <<number;
	return 0;
}