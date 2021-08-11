#include<iostream>
using namespace std;
int arr[102];
int brr[102];
int sub[102];
int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin >>n;
		int suma=0,sumb=0;
		for(int i=1;i<=n;i++){
			cin >>arr[i];
			suma+=arr[i];
		}
		for(int i=1;i<=n;i++){
			cin >>brr[i];
			sumb+=brr[i];
		}
		if(suma!=sumb){
			cout <<-1<<endl;
			continue;
		}
		int m=0;
		for(int i=1;i<=n;i++){
			sub[i]=arr[i]-brr[i];
			if(sub[i]>0) m+=sub[i];
		}
		cout <<m<<endl;
		for(int k=0;k<m;k++){
			int i;
			for(i=1;i<=n;i++){
				if(sub[i]>0)break;
			}
			int j;
			for(j=1;j<=n;j++){
				if(sub[j]<0) break;
			}
			cout <<i<<' '<<j<<endl;
			sub[i]--;
			sub[j]++;
		}
	}
	return 0;
}