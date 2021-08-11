#include<bits/stdc++.h>
using namespace std;
int j[2003];
int o[2003];
int n;

int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		int len_j=0,len_o=0;
		for(int i=1;i<=n;i++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp%2)j[++len_j]=tmp;
			else o[++len_o]=tmp;
		}
		for(int i=1;i<=len_j;i++){
			cout <<j[i]<<' ';
		}
		for(int i=1;i<=len_o;i++){
			cout <<o[i]<<' ';
		}
		cout <<endl;
	}
	return 0;
}