#include<bits/stdc++.h>
using namespace std;
//int arr[30009];
int arr;
int sum[3];
//bool cmp(int a,int b) {
//	return a>b;
//}
int main(){
	int t;cin >>t;
	while(t--){
		int n;cin>>n;
		sum[0]=0;sum[1]=0;sum[2]=0;
//		cout <<sum[0]<<' '<<sum[1]<<' '<<sum[2]<<endl;
		for(int i=1;i<=n;i++){
			scanf("%d",&arr);
			arr%=3;
			if(arr==0)sum[0]++;
			if(arr==1)sum[1]++;
			if(arr==2)sum[2]++;
		}
//		cout <<"ÊäÈëÍê±Ï"<<endl;
//		cout <<sum[0]<<' '<<sum[1]<<' '<<sum[2]<<endl;
		int all=0;
		for(int j=3;j<6;j++){
			if(sum[j%3]<n/3){
//				cout <<"xiaaoyu"<<endl;
				if(sum[(j-1)%3]>n/3) all+=min((sum[(j-1)%3]-(n/3)),(n/3)-sum[j%3]);
				if(sum[(j+1)%3]>n/3) all+=min((sum[(j+1)%3]-(n/3)),(n/3)-sum[j%3])*2;
			}
//			cout <<"all-"<<j%3<<':'<<all<<endl;
		}
//		sort(sum,sum+3,cmp);
//		if(sum[0]>n/3){
//			all+=sum[0]-(n/3);
//			sum[1]+=sum[0]-(n/3);
//		}
//		if(sum[1]>n/3){
//			all+=sum[1]-(n/3);
//		}
		cout <<all<<endl;
	}
	
	return 0;
}