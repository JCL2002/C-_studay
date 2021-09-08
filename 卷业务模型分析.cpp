#include<bits/stdc++.h>
using namespace std;
#define inf 100000000.0d;
int arr[100005];
//int brr[100005];
int crr[100005];
int m;
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>m;
		for(int i=1;i<=m;i++) cin >>arr[i];
		for(int i=1;i<=m;i++) cin >>arr[i];
		for(int i=1;i<=m;i++) cin >>crr[i];
		double left=-inf double right=inf;
		bool flag=1;
		for(int i=1;i<m;i++){
			double L,R;
			L=(double)(crr[i+1]-crr[i])/(arr[i+1]-arr[i])-abs((double)20/abs(arr[i+1]-arr[i]));
			R=(double)(crr[i+1]-crr[i])/(arr[i+1]-arr[i])+abs((double)20/abs(arr[i+1]-arr[i]));
			if(L>right||R<left){
				flag=0;
				break;
			}
			left=max(left,L);
			right=min(right,R);
		}
		if(flag)cout <<2<<endl;
		else cout <<1<<endl;
	}
	return 0;
}