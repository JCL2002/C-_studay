 #include<bits/stdc++.h>
 using namespace std;
 int a[302];//Monocarp的序列
 int b[302];//Polycarp的序列
 int res[604];//结果缓存
 int main(){
	int t;cin >>t;
	while(t--){
		int k,n,m;
		cin >>k>>n>>m;
		for(int i=1;i<=n;i++){
			cin >>a[i];
		}
		for(int i=1;i<=m;i++){
			cin >>b[i];
		}
		int A=1,B=1;int j=1;
		bool flag=true;
		for(int i=1;i<=n+m;i++){
			if(A<=n&&B<=m){
				if(a[A]<=k){
					if(a[A]==0) k++;
					res[j++]=a[A++];
				}
				else if(b[B]<=k){
					if(b[B]==0) k++;
					res[j++]=b[B++];
				}
				else{
					cout <<-1;
					flag=false;
					break;
				}
			}
			else if(A<=n){
				if(a[A]<=k){
					if(a[A]==0) k++;
					res[j++]=a[A++];
				}
				else{
					cout <<-1;
					flag=false;
					break;
				}
			}
			else{//B,<=n
				if(b[B]<=k){
					if(b[B]==0) k++;
					res[j++]=b[B++];
				}
				else{
					cout <<-1;
					flag=false;
					break;
				}
			}
		}
		if(flag){//其实可以根据j来判断
			for(int i=1;i<=n+m;i++){
				cout <<res[i]<<' ';
			}
		}
		cout <<endl;
	}
	return 0;
}