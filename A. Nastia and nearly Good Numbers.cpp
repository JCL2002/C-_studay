#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;long long A,B,x,y,z;
	cin >>t;
	for(int i=0;i<t;i++){
		scanf("%lld %lld",&A,&B);
		if(B==1){
			printf("NO\n");
			continue;
		}
		else{
			x=B*A;
			y=(B+1)*A;
			z=(2*B+1)*A;
		}
		printf("YES\n%lld %lld %lld\n",x,y,z);
	}
	return 0;
}