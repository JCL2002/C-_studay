#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char x[101],y[101],z[101];
	cin >>x>>y;
	for(int i=0;i<n;i++){
		if(y[i]>x[i]){
			printf("-1");
			return 0;
		}
		else if(y[i]==x[i]){
			z[i]=x[i]+1;
		}
		else{
			z[i]=y[i];
		}
	}
	z[n]='\0';
	cout <<z;
	return 0;
}