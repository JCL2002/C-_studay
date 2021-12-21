#include<bits/stdc++.h>
using namespace std;
int m,v,n;
int a[10001],b[10001],c[10001];
int f[1001][1001];
string ans[1001][1001];
int main(){
	cin>>m>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i];j--){
			for(int k=v;k>=b[i];k--){
				if(f[j-a[i]][k-b[i]]+c[i]>f[j][k]){
					f[j][k]=f[j-a[i]][k-b[i]]+c[i];
					ans[j][k]=ans[j-a[i]][k-b[i]]+char(i);
				}
			}
		}
	}
	cout<<f[m][v]<<endl;
	for(int i=0;i<(int)ans[m][v].size();i++){
		int temp=ans[m][v][i];
		cout<<temp<<" ";
	}
	cout<<endl;
	return 0;
}
