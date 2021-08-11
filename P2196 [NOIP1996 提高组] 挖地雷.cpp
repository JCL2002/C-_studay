#include<bits/stdc++.h>
using namespace std;
int num[30];
bool MAP[30][30];
int n;
int ans[30];
stack<int>s;
void back(int x){
	s.push(x);
	for(int i=1;i<=n;i++){
		if(MAP[i][x]){
			if(ans[i]==ans[x]-num[x]){
				back(i);
			}
		}
	}
}
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>num[i];
	}
	for(int i=1;i<n;i++){
		bool tmp;
		for(int j=i+1;j<=n;j++){
			cin >>tmp;
			if(tmp){
				MAP[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)ans[i]=num[i];
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(MAP[i][j]){
				if(ans[i]+num[j]>ans[j])ans[j]=ans[i]+num[j];
			}
		}
	}
//	cout <<endl;
//	for(int i=1;i<=n;i++){
//		cout <<ans[i]<<" ";
//	}
//	cout <<endl;
	int mmax=0;
	int mi=0;
	for(int i=1;i<=n;i++){
		if(ans[i]>mmax){
			mmax=ans[i];
			mi=i;
		}
	}
	back(mi);
	while(!s.empty()){
		cout <<s.top();
		s.pop();
		if(!s.empty()) cout <<" ";
	}
	cout <<endl;
	cout <<mmax;
	return 0;
}