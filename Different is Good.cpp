#include<bits/stdc++.h>
using namespace std;
int n;
char s[100005];
bool vis[256];
int main(){
	cin >>n;
	cin >>s;
	if(n>26){
		cout <<-1;
		return 0;
	}
	else{
		for(int i=0;i<n;i++){
			vis[(int)s[i]]=1;
		}
		int num=0;
		for(int i=(int)'a';i<=(int)'z';i++){
			if(vis[i])num++;
		}
		cout <<n-num<<endl;
	}
	return 0;
}