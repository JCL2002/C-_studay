#include<bits/stdc++.h>
using namespace std;
char s[105];
int n;
int main(){
	cin >>s;
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(((int)s[i]-'0')%8==0){
			cout <<"YES"<<endl;
			cout <<s[i];
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if((10*(int)(s[i]-'0')+(int)(s[j]-'0'))%8==0){
				cout <<"YES"<<endl;
				cout <<s[i]<<s[j];
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if((100*(int)(s[i]-'0')+10*(int)(s[j]-'0')+s[k]-'0')%8==0){
					cout <<"YES"<<endl;
					cout <<s[i]<<s[j]<<s[k];
					return 0;
				}
			}
		}
	}
	cout <<"NO"<<endl;
	return 0;
}