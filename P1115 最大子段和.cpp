#include<bits/stdc++.h>
using namespace std;
short int a;
int sum[200001];
int main(){
	int n;
	cin>>n;
	int min=0,max=0,MAX=-900000000;
	for(int i=1;i<=n;i++){
		scanf("%hd",&a);
		sum[i]+=sum[i-1]+a;
		if(sum[i]<min) min=sum[i];
		if(sum[i]-min>max) max=sum[i]-min;
		if(a>MAX) MAX=(int)a;
	}
	if(max<1){
		cout <<MAX;
	}
	else{
		cout <<max;
	}
	return 0;
}