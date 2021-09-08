#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int n;
int a,b,e,x;
int main(){
	int  t;
	cin >>t;
	while(t--){
		cin >>a>>b;
			e=(a+b)/2;
			int start=max(0,e-b);
			int end=min(e,a);
		if((a+b)%2){
			n=0;
			for(x=end;x>=start;x--){
				arr[++n]=a+e-2*x;
			}
			e++;
			int start=max(0,e-b);
			int end=min(e,a);
			for(x=end;x>=start;x--){
				arr[++n]=a+e-2*x;
			}
			sort(arr+1,arr+1+n);
			cout <<n<<endl;
			for(int i=1;i<=n;i++) cout <<arr[i]<<" ";
		}
		else{
			cout <<end-start+1<<endl;
			for(x=end;x>=start;x--){
				cout <<a+e-2*x<<" ";
			}
		}
		cout <<endl;
	}
	return 0;
}