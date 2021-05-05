#include<bits/stdc++.h>
using namespace std;
int main(){
	 int h2,a2,h1,a1,c1,times=0;
	cin >>h1>>a1>>c1;
	cin >>h2>>a2;
	bool action[10005];
	while(h2>0){
		times++;
		if(a2>=h1&&h2>a1){
			
			action[times]=false;
			h1+=(c1-a2);
		}
		else{
			action[times]=true;
			h1-=a2;
			h2-=a1;
		}
	}
	cout <<times<<endl;
	for(int i=1;i<=times;i++){
		if(action[i]){
			printf("STRIKE\n");
		}
		else{
			printf("HEAL\n");
		}
	}
	return 0;
}