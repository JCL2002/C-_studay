#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N];
char turn[N];
int si;
int main(){
	int t;cin >>t;
//	int T=t;
	while(t--){
		int a,b;
		cin >>a>>b;
		cin >>s;
		si=0;
//		if(T==11215){
//			if(T-t==212){
//				cout <<s<<endl;
//				cout <<a<<" "<<b<<endl;
//			}
//			else continue;
//		}
		int len=strlen(s);
		int zero=0,one=0;
		for(int i=0;i<len;i++){
			if(s[i]=='0'||s[i]!=s[i+1]){
				turn[si++]=s[i];
			}
		}
		int fr=0,ls=len-1;
		for(int i=0;i<si;i++){
			if(turn[i]=='1'){
				fr=i;
				break;
			}
		}
		for(int i=si-1;i>=0;i--){
			if(turn[i]=='1'){
				ls=i;
				break;
			}
		}
		for(int i=fr;i<=ls;i++){
			cout <<turn[i];
			if(turn[i]=='1')one++;
			else zero++;
		}
		cout <<min(one*a,a+zero*b)<<endl;
	}
	return 0;
}