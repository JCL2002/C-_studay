#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
	long long a;
	int i;
};
node arr[N];
bool cmp(node a,node b){
	return a.a<b.a;
}
int main(){
	int t;cin >>t;
	while(t--){
		int n,k;
		cin >>n>>k;
		for(int i=1;i<=n;i++){
			cin >>arr[i].a;
			arr[i].i=i;
		}
		sort(arr+1,arr+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout <<arr[i].a<<": "<<arr[i].i<<endl;
//		}
		int num=0;
		int j=n+1;
		for(int i=1;i<=n;i++){
			if(arr[i].i!=j+1) num++;
			j=arr[i].i;
		}
//		cout <<num<<endl;
		if(num>k)cout <<"NO"<<endl;
		else cout <<"YES"<<endl;
	}
	return 0;
}