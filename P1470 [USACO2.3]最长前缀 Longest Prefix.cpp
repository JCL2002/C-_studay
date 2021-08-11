#include<bits/stdc++.h>
using namespace std;
string p[202],s;
int n;
bool able[200005]={1};
bool dp(int x){
	for(int i=0;i<n;i++){
		int t=p[i].size();
		if(x>=t&& able[x-t] &&s.substr(x-t,t)==p[i]) return 1;
	}
	return 0;
}
int main(){
	string cache;
	string end=".";
	for(;cin >>cache,cache!=end;p[n++]=cache);
	while(cin >>cache) s+=cache;
	for(int i=1;i<=(int)s.size();i++){
		able[i]=dp(i);
	}
	for(int i=(int)s.size();i>=0;i--){
		if(able[i]){
			cout <<i;
			return 0;
		}
	}
	return 0;
}