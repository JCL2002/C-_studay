#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int arr[N];
int num[N];
int n;
void init(){
	for(int i=1;i<=n;i++){
		num[i]=0;
	}
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++)cin >>arr[i];
		for(int i=1;i<=n;i++){
			if(arr[i]!=arr[i-1])num[arr[i]]++;
		}
		if(arr[1]==arr[n]){
			if(num[arr[1]]==2){
				cout <<1<<endl;
				init();
				continue;
			}
			if(num[arr[1]]==1){
				cout <<0<<endl;
				init();
				continue;
			}
		}
		if(num[arr[1]]==1){
			cout <<1<<endl;
			init();
			continue;
		}
		if(num[arr[n]]==1){
			cout <<1<<endl;
			init();
			continue;
		}
		num[arr[1]]--;num[arr[n]]--;
		int mmin=N;
		for(int i=1;i<=n;i++){
			if(num[i])mmin=min(mmin,num[i]);
		}
		cout <<mmin+1<<endl;
		init();
	}
	return 0;
}