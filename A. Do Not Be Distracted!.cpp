#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;int n;char order[55];
	cin >>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cin>>order;
		bool suspect=false;
//		bool t=false,o=false;
		for(int j=0;j<n;j++){
			char current=order[j];
			for(int k=0;k<j;k++){
				if(order[k]==current){//从这一点开始找
					for(int z=k+1;z<j;z++){
						if(order[z]!=current) suspect=true;
					}
				}
			}
		}
		if(suspect){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}