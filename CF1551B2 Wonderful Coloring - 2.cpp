#include<bits/stdc++.h>
using namespace std;
struct MAP{
	int i;//原下标
	int a;//内容
	int cnt;//出现次数
};
int cnt[200005];
MAP m[200005];
int ans[200005];
int n,k;
bool cmp(MAP a,MAP b){
	if(a.cnt==b.cnt) return a.a>b.a;
	return a.cnt>b.cnt;
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n>>k;
		for(int i=1;i<=n;i++){
			cin >>m[i].a;
			m[i].i=i;
			cnt[m[i].a]++;
		}
		for(int i=1;i<=n;i++){
			m[i].cnt=cnt[m[i].a];
		}
//		for(int i=1;i<=n;i++)cout <<cnt[i]<<' ';
//		cout <<endl;
		sort(m+1,m+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout <<m[i].cnt<<' ';
//		}
//		cout <<endl;
//		for(int i=1;i<=n;i++){
//			cout <<m[i].a<<' ';
//		}
//		cout <<endl;
//		for(int i=1;i<=n;i++){
//			cout <<m[i].i<<' ';
//		}
//		cout <<endl;
		int lst=0;
		for(int i=1;i<=n;i++){
			if(m[i].cnt>k){
				for(int j=0;j<k;j++){
					ans[m[i+j].i]=j+1;
				}
				i+=m[i].cnt-1;
			}
			else{
				if(n-i>=k-(lst%k+1)){//剩余的数量足够一个轮回
					ans[m[i].i]=lst%k+1;
					lst++;
				}
				else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)cout <<ans[i]<<' ';
		cout <<endl;
		memset(m,0,n*sizeof(MAP)+2);
		memset(ans,0,n*sizeof(int)+2);
		memset(cnt,0,n*sizeof(int)+2);
	}
}