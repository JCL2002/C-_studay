#include<bits/stdc++.h>
using namespace std;
int arr[2000006];
struct nu{
	int num;
	int i;
};
nu num[2000006];
int n;
void init(){
	for(int i=1;i<=n;i++){
		arr[i]=0;
		num[i].i=0;
		num[i].num=0;
	}
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>arr[i];
		}
//		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++){
			num[arr[i]].num++;
			num[arr[i]].i=i;
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(num[i].num==1){
				cout <<num[i].i<<endl;
				flag=0;
				break;
			}
		}
		if(flag)cout <<-1<<endl;
		init();
	}
	return 0;
}