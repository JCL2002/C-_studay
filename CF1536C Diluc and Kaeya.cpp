#include<bits/stdc++.h>
using namespace std;
char s[500005];
struct rato{
	int d;
	int k;
};
rato arr[500005];
int ans[500005];
int n;
inline void init(){
	for(int i=1;i<=n;i++)ans[i]=0;
}
inline bool test(int i,int d,int k){
	if(d*arr[i].k==k*arr[i].d)return 1;
	return 0;
}
int gcd(int a,int b){
	return !b? a:gcd(b,a%b);
}
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		cin >>s+1;
		init();
		int d=0,k=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='D')d++;
			else k++;
			arr[i].d=d;
			arr[i].k=k;
			int step=1;
			if(d&&k){
				step=(d+k)/gcd(d,k);
			}
//			cout <<step<<endl;
			for(int j=1;j*step<=i;j++){
//				cout <<"*";
				if(test(i-j*step,d,k)){
//					cout <<"#"<<endl;
					ans[i]=ans[i-j*step]+1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout <<ans[i]<<" ";
		}
		cout <<endl;
//		cout <<ans[100]<<endl;
	}
	return 0;
}