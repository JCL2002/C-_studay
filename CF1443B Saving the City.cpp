#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N];
char turn[N];
int dp[N];
void init(int n){
	for(int i=0;i<=n;i++) {
		turn[i]=0;
		dp[i]=0;
	}
}
int main(){
	int t;cin >>t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cin >> s;
		int l=0,r=0;
		int num=0;
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='1'){
				l=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(s[i]=='1'){
				r=i;
				break;
			}
		}
		for(int i=l;i<=r;i++){
			if(s[i]=='0'||s[i]!=s[i+1]){
				turn[num++]=s[i];
			}
		}
		if(turn[0]=='1')dp[0]=a;
		int k=0;
		for(int i=1;i<num;i++){
			if(turn[i]=='0'){
				dp[i]=dp[i-1];
			}
			else{
				dp[i]=min((i-k-1)*b,a)+dp[i-1];
				k=i;
			}
		}
		cout <<dp[num-1]<<endl;
		init(num);
	}
	return 0;
}