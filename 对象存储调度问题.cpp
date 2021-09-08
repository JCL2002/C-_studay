#include<bits/stdc++.h>
using namespace std;
int num[35];//2^num[i]
int n,m;
priority_queue<long long,vector<long long> >q;
long long power(int x){//2^x
	long long base=2;
	long long res=1;
	while(x){
		if(x&1) res*=base;
		base*=base;
		x>>=1;
		
	}
	return res;
}
void init(){
	for(int i=0;i<35;i++) num[i]=0;
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n>>m;
		int mmax=0;
		init();
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			long long tmp;
			cin >>tmp;
			int ti=-1;
			while(tmp){
				ti++;
				tmp/=2;
			}
			num[ti]++;
			mmax=max(mmax,ti);
		}
		for(int i=1;i<=m;i++){
			long long tmp;
			cin >>tmp;
			q.push(tmp);
		}
		for(int i=1;i<=m;i++){
			for(int j=mmax;j>=0;j--){
				if(num[j]){
					long long kk=power(j);
					long long top=q.top();
//					cout <<"kk: "<<kk<<"  top: "<<top<<endl;
					if(kk<=top){
						top-=kk;
						q.pop();
						q.push(top);
						num[j]--;
						j++;
						continue;
					}
				}
			}
		}
		bool flag=1;
		for(int i=1;i<=mmax;i++){
			if(num[i]){
				flag=0;
				break;
			}
		}
		if(flag)cout <<"Yes"<<endl;
		else cout <<"No"<<endl;
	}
	return 0;
}