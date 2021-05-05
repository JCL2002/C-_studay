#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

using namespace std;
unsigned int power(int n){
	int i=0;
	unsigned int base=1;
	for(i=0;i<n;i++){
		base*=2;
	}
	return base;
}
bool tst(unsigned int n){
//	cout<<n<<endl;
	if(n==2||n==4) return true;
	int i=sqrt(n);
	for(int j=i-1;j>=2;j--){
		if(n%(j*j)==0){
			return tst(n/(j*j));
		}
	}
	return false;
}
int main(){
	srand(time(NULL));
	unsigned int n;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
//		n=900000000+rand();
		scanf("%d",&n);
		if(n==1){
			printf("NO\n");
			continue;
		}
		if(tst(n)){
			printf("YES\n");
			continue;
		}
		int number=0;
		for(int j=0;j<31;j++){
			if(n&(1<<j)) number++;
		}
		if(number==1){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}