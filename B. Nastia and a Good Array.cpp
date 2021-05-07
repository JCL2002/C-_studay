#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int I[10001];
int res[10001];
bool gcd(int a,int b){
	if(!(a&1)&&!(b&1)) return false;
	for(int i=3;i<=min(a,b);i+=2){
//		cout <<"gcd:"<<a<<' '<<b<<endl;
		if(a%i==0&&b%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int t;cin >>t;
	for(int i=1;i<=t;i++){
		
		int n;
		scanf("%d",&n);
//		cin >>n;
		for(int j=1;j<=n;j++){
			scanf("%d",arr+j);
//			cin >>arr[j];
		}
		int number=0;
		for(int j=2;j<=n;j++){//找出需要调整的对
			if(!gcd(arr[j-1],arr[j])){
//				cout <<arr[j-1] <<' '<<arr[j]<<endl;
				number++;
				int m=min(arr[j-1],arr[j]);
				arr[j-1]=m;arr[j]=m+1;
				res[2*number-1]=m;res[2*number]=m+1;
//				if(m==arr[j-1]){
////					printf("%d %d\n",m,m+1);
//					arr[j]=m+1;res[2*number-1]=m;res[2*number]=m+1;
//				}
//				else{
////					printf("%d %d\n",m+1,m);
//					arr[j-1]=m+1;res[2*number-1]=m+1;res[2*number]=m;
//				}
				I[2*number-1]=j-1;I[2*number]=j;
			}
		}
		printf("%d\n",number);
		for(int j=1;j<=number;j++){
			printf("%d %d %d %d\n",I[2*j-1],I[2*j],res[2*j-1],res[2*j]);
//			int m=min(arr[I[2*j-1]],arr[I[2*j]]);
//			if(m==arr[I[2*j-1]]){
//				printf("%d %d\n",m,m+1);
//			}
//			else{
//				printf("%d %d\n",m+1,m);
//			}
		}
	}
	return 0;
}