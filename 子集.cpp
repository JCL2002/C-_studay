#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned int i,j,n;
	int element[12];
	char flag='f';
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",element+i);
	}
	for(i=0;i<(unsigned int)(1<<n);i++){
		flag='f';
		printf("{");
		for(j=0;j<n;j++){
			if(i&(unsigned int)(1<<j)){
				printf("%d,",element[j]);
				flag='t';
			}
		}
		if(flag=='t'){
			printf("\b");
		}
		printf("}\n");
	}
	return 0;
}