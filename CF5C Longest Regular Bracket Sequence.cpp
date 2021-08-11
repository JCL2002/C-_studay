#include<bits/stdc++.h>
using namespace std;
char s[1000006];
bool ped[1000006];
int num[1000006];
stack<int>z;
int main(){
	cin >>s+1;
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			z.push(i);
		}
		else{
			if(!z.empty()){
				int r=z.top();
				z.pop();
				ped[i]=ped[r]=1;
			}
		}
	}
	bool flag=0;int j=0;
	int mmax=0;
	for(int i=1;i<=n+1;i++){
		if(flag){
			if(ped[i])continue;
			num[i-j]++;
			mmax=max(mmax,i-j);
			flag=0;
		}
		else{
			if(!ped[i])continue;
			j=i;
			flag=1;
		}
	}
	if(mmax){
		cout <<mmax<<" "<<num[mmax];
		return 0;
	}
	cout <<"0 1";
	return 0;
}