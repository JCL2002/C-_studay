#include<bits/stdc++.h>
using namespace std;
#define int long long
long long ans;
int dp[200005];//表示当前字符最多能与前面多少位匹配,可以用滚动的方式优化
char s[200005];
int num[200005];//一连出现几次?
void init(int n){
	for(int i=0;i<=n;i++){
		num[i]=0;
	}
}
signed main(){
	int t;
	cin >>t;
	while(t--){
		cin >>s;
		int len=strlen(s);
		dp[0]=1;
		ans=0;
		for(int i=1;i<len;i++){
			if(s[i]=='?')num[i]=num[i-1]+1;
		}
		for(int i=1;i<len;i++){
			if(s[i]=='0'){//当前字符是0
				if(s[i-1]=='1'||s[i-1]=='?'||s[i-1]=='?'+2){
					dp[i]=dp[i-1]+1;
				}
				else if(s[i-1]=='0'){
					dp[i]=1;
				}
				else{//前一位是?但是要变成0
					dp[i]=num[i-1]+1;
				}
			}
			else if (s[i]=='1'){//当前字符是1
				if(s[i-1]=='0'||s[i-1]=='?'||s[i-1]=='?'+1){
					dp[i]=dp[i-1]+1;
				}
				else if(s[i-1]=='1'){
					dp[i]=1;
				}
				else{//前一位是?但是要变成1
					dp[i]=num[i-1]+1;
				}
			}
			else{//当前字符是?
				dp[i]=dp[i-1]+1;//万金油
				if(s[i-1]=='0'||s[i-1]=='?'+1){
					s[i]='?'+2;
				}
				else if(s[i-1]=='1'||s[i-1]=='?'+2){
					s[i]='?'+1;
				}
			}
		}
		for(int i=0;i<len;i++){
			ans+=dp[i];
		}
		cout <<ans<<endl;
		init(len);
	}
	return 0;
}