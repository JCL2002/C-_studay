#include<bits/stdc++.h>
using namespace std;
#define int long long
long long ans;
int dp[200005];//��ʾ��ǰ�ַ��������ǰ�����λƥ��,�����ù����ķ�ʽ�Ż�
char s[200005];
int num[200005];//һ�����ּ���?
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
			if(s[i]=='0'){//��ǰ�ַ���0
				if(s[i-1]=='1'||s[i-1]=='?'||s[i-1]=='?'+2){
					dp[i]=dp[i-1]+1;
				}
				else if(s[i-1]=='0'){
					dp[i]=1;
				}
				else{//ǰһλ��?����Ҫ���0
					dp[i]=num[i-1]+1;
				}
			}
			else if (s[i]=='1'){//��ǰ�ַ���1
				if(s[i-1]=='0'||s[i-1]=='?'||s[i-1]=='?'+1){
					dp[i]=dp[i-1]+1;
				}
				else if(s[i-1]=='1'){
					dp[i]=1;
				}
				else{//ǰһλ��?����Ҫ���1
					dp[i]=num[i-1]+1;
				}
			}
			else{//��ǰ�ַ���?
				dp[i]=dp[i-1]+1;//�����
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