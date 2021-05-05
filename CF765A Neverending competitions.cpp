#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned int n,go=0,back=0;
	cin >>n;
	char home[4],set[4],arr[4],cache[9];
	cin>>home;
	for(unsigned int i=0;i<n;i++){
		scanf("%s",cache);
		for(int j=0;j<3;j++){
			set[j]=cache[j];
			arr[j]=cache[j+5];
		}
		set[3]=arr[3]='\0';
		if(strcmp(set,home)==0){
			go++;
		} 
		if(strcmp(arr,home)==0) back++;
	}
	if(go==back) printf("home");
	else printf("contest");
	return 0;
}