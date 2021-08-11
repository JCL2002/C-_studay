#include<bits/stdc++.h>
using namespace std;
char s[532];
char T[526];
int main(){
	int t; cin >>t;
	while(t--){
		cin >>s;
		cin >>T;
		int l_s=(int)strlen(s);
		int l_t=(int)strlen(T);
		bool tar=false;
		for(int i=0;i<l_s;i++){
			if(T[0]==s[i]){
				int left_step=0,right_step=0;
				bool left=true,right=true;
				if(l_t==1){
					cout <<"YES"<<endl;
					tar=true;
					break;
				}
				while(right){
					right_step++;
					if(T[right_step]==s[i+right_step]){
						if(right_step==l_t-1){
							cout <<"YES"<<endl;
							tar=true;
							left=false;
							right=false;
							continue;
						}
						continue;
					}
					else{
						right=false;
						right_step--;
					}
				}
				while(left){
					left_step++;
					if(i+right_step-left_step>=0&&T[right_step+left_step]==s[i+right_step-left_step]){
						if(right_step+left_step==l_t-1){
							cout <<"YES"<<endl;
							tar=true;
							break;
						}
					}
					else{
						tar=false;
						break;
					}
				}
				if(tar) break;
				else continue;
			}
		}
		if(!tar) cout <<"NO"<<endl;
		
	}
	return 0;
}