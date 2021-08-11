#include<bits/stdc++.h>
using namespace std;
char str[55];
char order[55];
int main(){
	int t;cin >>t;
	while(t--){
		int n;
		cin >>n;
		cin >>str;
		int num=0;
		strcpy(order,str);
		sort(order,order+n);
		for(int i=0;i<n;i++){
			if(order[i]!=str[i])num++;
		}
		cout <<num<<endl;
	}
	return 0;
}