#include<bits/stdc++.h>
using namespace std;
char S[200008];
int main(){
	int t;
	cin >>t;
	for(int i=1;i<=t;i++){
		cin >>S;
		int len=strlen(S);
		long long num=0;
		int j=0;int L=1;char current=S[0];
		while(j<len){
			if(current=='0'){
				if(S[j+1]=='1'||S[j+1]=='?'){
					L++;
					current='1';
				}
				else{
					num+=L*(L+1)/2;
					L=1;
					if(S[j]=='?'){
						current='?';
						continue;
					}
					else{
						current=S[j+1];
					}
				}
			}
			else if(current=='1'){
				if(S[j+1]=='1'){
					num+=L*(L+1)/2;
					L=1;
					if(S[j]=='?'){
						current='?';
						continue;
					}
					else{
						current=S[j+1];
					}
				}
				else{
					L++;
					current='0';
				}
			}
			else{//?
				if(S[j+1]=='0'){
					L++;
					current='0';
				}
				else if(S[j+1]=='1'){
					L++;
					current='1';
				}
				else{
					L++;
					current='?';
				}
			}
			
			j++;
		}
		num+=L*(L+1)/2;
		cout <<num<<endl;
	}
	
	return 0;
}