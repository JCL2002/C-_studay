#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned short t;
	cin >>t;
	for(unsigned short i=0;i<t;i++){
		unsigned int a,b,c;
		scanf("%u %u",&a,&b);
		c=a&b;
		a^=c;b^=c;
		printf("%u\n",(a+b));
	}
	return 0;
}