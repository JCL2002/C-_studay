#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
	int t;cin >>t;
	while(t--){
		cin >> s+1;
		s[0]='0';
		int len=strlen(s);
		bool flag=0;
		bool ok=1;
		for(int i=1;i<len;i++){
			if(flag){//处于高
				if(s[i]=='0'&&i<len-1&&s[i+1]=='0'){
					ok=0;
					break;
				}
			}
			else{//处于低
				if(s[i]=='1'&&i<len-1&&s[i+1]=='1') flag=1;//不得不向高出转移
			}
		}
		if(ok) cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
	}
	return 0;
}