#include<bits/stdc++.h>
using namespace std;
int dif[100005];//²î·ÖÊý×é

int main(){
	int n;int a,b=0;
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		dif[i]=a-b;
		b=a;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(dif[i]>0){
			sum+=dif[i];
		}
	}
	cout <<sum;
	return 0;
}