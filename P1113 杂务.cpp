#include<bits/stdc++.h>
using namespace std;
int ans[10005];
int res;
//¶¯Ì¬¹æ»®
int main(){
	int n;cin >>n;
	for(int i=1;i<=n;i++){
		int len,tmp;
		scanf("%d %d %d",&i,&len,&tmp);
		int MAX=0;
		while(tmp){
			MAX=max(MAX,ans[tmp]);
			scanf("%d",&tmp);
		}
		ans[i]=MAX+len;
		res=max(res,ans[i]);
	}
	cout <<res;
}