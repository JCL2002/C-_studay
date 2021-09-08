#include<bits/stdc++.h>
using namespace std;
struct task{
	int min;
	int num;
};
task arr[100005];
bool cmp(task a,task b){
	return a.min<b.min;
}
int n;
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++){
			int mmin=0;
			int m;
			cin >>m;
			for(int j=1;j<=m;j++){
				int tmp;
				cin >>tmp;
				mmin=max(mmin,tmp+2-j);
			}
			arr[i].min=mmin;
			arr[i].num=m;
		}
		sort(arr+1,arr+1+n,cmp);
//		cout <<endl;
//		for(int i=1;i<=n;i++){
//			cout <<arr[i].min<<"  :   "<<arr[i].max<<endl;
//		}
//		cout <<endl;
		int ans=arr[1].min,sum=arr[1].num;
		for(int i=2;i<=n;i++){
			ans=max(ans,arr[i].min-sum);
			sum+=arr[i].num;
		}
		cout <<ans<<endl;
	}
	return 0;
}