#include<bits/stdc++.h>
using namespace std;
int n;
char str[1003];

inline bool test(int a,int b,int c){//¼ì²âÄÜ²»ÄÜÆ¥Åä
	if(b==0&&c==0){
		for(int i=0;i<n;i++){
			if(str[i]=='a'+a)return true;
		}
		return false;
	}
	if(c==0){
		for(int i=0;i<n-1;i++){
			if(str[i]=='a'+a){
				if(str[i+1]=='a'+b-1){
					return true;
				}
			}
		}
		return false;
	}
	for(int i=0;i<n-2;i++){
		if(str[i]=='a'+a){
			if(str[i+1]=='a'+b-1){
				if(str[i+2]=='a'+c-1){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin >>n;
		cin >>str;
		bool flag=false;
		for(int i=0;i<26;i++){
			if(!test(i,0,0)){
				flag=true;
				printf("%c\n",'a'+i);
				break;
			}
		}
		if(!flag){
			for(int i=0;i<26;i++){
				for(int j=1;j<27;j++){
					if(!test(i,j,0)){
						flag=true;
						printf("%c%c\n",'a'+i,'a'+j-1);
						break;
					}
				}
				if(flag) break;
			}
		}
		if(!flag){
			for(int i=0;i<26;i++){
				for(int j=1;j<27;j++){
					for(int k=1;k<27;k++){
						if(!test(i,j,k)){
							flag=true;
							printf("%c%c%c\n",'a'+i,'a'+j-1,'a'+k-1);
							break;
						}
					}
					if(flag) break;
				}
				if(flag) break;
			}
		}
	}
	
	return 0;
}